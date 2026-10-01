`include "defines.v"

module rv32i_top #(
    parameter INST_HEX  = "hex/inst_mem.hex",
    parameter DATA_HEX  = "hex/data_mem.hex",
    parameter BASE_ADDR = 32'h00000000,
    parameter ECALL_HALT = 1'b1,
    // The byte-addressable simulation RAM transparently supports unaligned
    // accesses by default; Linux-style trap policy can be selected explicitly.
    parameter TRAP_MISALIGNED = 1'b0,
    parameter TRAP_INST_MISALIGNED = 1'b1,
    parameter COHERENT_CODE_WRITES = 1'b0,
    parameter UNIFIED_MEMORY = 1'b0,
    parameter INST_WORD_COUNT = `INST_MEM_WORDS,
    parameter DATA_WORD_COUNT = `DATA_MEM_WORDS,
    parameter TIMER_IRQ_ENABLE = 1'b1,
    parameter BOOT_A0 = 32'b0,
    parameter BOOT_A1 = 32'b0
) (
    input         clk,
    input         rst,
    output [31:0] pc_debug,
    output [31:0] instr_debug,
    output [31:0] alu_result_debug,
    output [31:0] mem_read_debug,
    output        halted
);
    wire [31:0] pc;
    wire [31:0] instr0, instr1;
    wire [31:0] unified_instr1;
    wire        mem_read0,  mem_write0;
    wire [31:0] mem_addr0,  mem_wdata0, mem_rdata0;
    wire [2:0]  mem_funct30;
    wire        mem_amo0, mem_amo_lr0, mem_amo_sc0;
    wire [4:0]  mem_amo_op0;
    wire        mem_read1,  mem_write1;
    wire [31:0] mem_addr1,  mem_wdata1, mem_rdata1;
    wire [2:0]  mem_funct31;
    wire        reg_write0, reg_write1;
    wire [4:0]  reg_wa0,    reg_wa1;
    wire [31:0] reg_wd0,    reg_wd1;
    wire        ecall, halt;
    wire        timer_irq;
    wire        timer_irq_raw;
    assign timer_irq = TIMER_IRQ_ENABLE && timer_irq_raw;

    // Slot 0 instruction fetch + shared dual-port data memory
    // Keep instance name "mem" so existing testbenches can introspect
    // data RAM via uut.mem.dmem.mem[...].
    mem_top #(
        .INST_HEX (INST_HEX),
        .DATA_HEX (DATA_HEX),
        .BASE_ADDR(BASE_ADDR),
        .COHERENT_CODE_WRITES(COHERENT_CODE_WRITES),
        .UNIFIED_MEMORY(UNIFIED_MEMORY),
        .INST_WORD_COUNT(INST_WORD_COUNT),
        .DATA_WORD_COUNT(DATA_WORD_COUNT)
    ) mem (
        .clk        (clk),
        .inst_addr  (pc),
        .inst_data  (instr0),
        .inst_addr1 (pc + 32'd4),
        .inst_data1 (unified_instr1),
        .mem_we0    (mem_write0),
        .mem_re0    (mem_read0),
        .mem_addr0  (mem_addr0),
        .mem_wdata0 (mem_wdata0),
        .mem_funct3_0(mem_funct30),
        .mem_amo0   (mem_amo0), .mem_amo_op0(mem_amo_op0),
        .mem_amo_lr0(mem_amo_lr0), .mem_amo_sc0(mem_amo_sc0),
        .mem_rdata0 (mem_rdata0),
        .mem_we1    (mem_write1),
        .mem_re1    (mem_read1),
        .mem_addr1  (mem_addr1),
        .mem_wdata1 (mem_wdata1),
        .mem_funct3_1(mem_funct31),
        .mem_rdata1 (mem_rdata1),
        .timer_irq  (timer_irq_raw)
    );

    // Slot 1 fetch uses the same backing array in unified mode; the legacy
    // split mode keeps its second instruction-memory read port.
    generate
        if (UNIFIED_MEMORY) begin : gen_unified_slot1
            assign instr1 = unified_instr1;
        end else begin : gen_split_slot1
            inst_mem #(
                .HEX_FILE(INST_HEX),
                .BASE_ADDR(BASE_ADDR),
                .WRITE_ENABLE(COHERENT_CODE_WRITES),
                .MEM_WORDS(INST_WORD_COUNT)
            ) imem_b (
                .clk         (clk),
                .addr        (pc + 32'd4),
                .instruction (instr1),
                .we0         (mem_write0 && !mem_amo0),
                .waddr0      (mem_addr0),
                .wdata0      (mem_wdata0),
                .wfunct30    (mem_funct30),
                .we1         (mem_write1),
                .waddr1      (mem_addr1),
                .wdata1      (mem_wdata1),
                .wfunct31    (mem_funct31)
            );
        end
    endgenerate

    core_top #(
        .RESET_PC(BASE_ADDR),
        .ECALL_HALT(ECALL_HALT),
        .TRAP_MISALIGNED(TRAP_MISALIGNED),
        .TRAP_INST_MISALIGNED(TRAP_INST_MISALIGNED),
        .BOOT_A0(BOOT_A0), .BOOT_A1(BOOT_A1)
    ) core (
        .clk           (clk),
        .rst           (rst),
        .timer_irq     (timer_irq),
        .instr0        (instr0),
        .instr1        (instr1),
        .mem_read_data0(mem_rdata0),
        .mem_read0     (mem_read0),
        .mem_write0    (mem_write0),
        .mem_addr0     (mem_addr0),
        .mem_wdata0    (mem_wdata0),
        .mem_funct30   (mem_funct30),
        .mem_amo0      (mem_amo0), .mem_amo_op0(mem_amo_op0),
        .mem_amo_lr0   (mem_amo_lr0), .mem_amo_sc0(mem_amo_sc0),
        .mem_read_data1(mem_rdata1),
        .mem_read1     (mem_read1),
        .mem_write1    (mem_write1),
        .mem_addr1     (mem_addr1),
        .mem_wdata1    (mem_wdata1),
        .mem_funct31   (mem_funct31),
        .pc_out        (pc),
        .reg_write0    (reg_write0),
        .reg_wa0       (reg_wa0),
        .reg_wd0       (reg_wd0),
        .reg_write1    (reg_write1),
        .reg_wa1       (reg_wa1),
        .reg_wd1       (reg_wd1),
        .ecall         (ecall),
        .halt          (halt)
    );

    assign pc_debug         = pc;
    assign instr_debug      = instr0;
    assign alu_result_debug = 32'b0;
    assign mem_read_debug   = mem_rdata0;
    assign halted           = halt;

endmodule
