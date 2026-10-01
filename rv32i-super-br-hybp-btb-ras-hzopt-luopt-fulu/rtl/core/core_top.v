`include "defines.v"

module core_top #(
    parameter RESET_PC = 32'h00000000,
    parameter ECALL_HALT = 1'b1,
    parameter TRAP_MISALIGNED = 1'b1,
    parameter TRAP_INST_MISALIGNED = 1'b1,
    parameter BOOT_A0 = 32'b0,
    parameter BOOT_A1 = 32'b0
) (
    input         clk,
    input         rst,
    input         timer_irq,
    input  [31:0] instr0,
    input  [31:0] instr1,
    input  [31:0] mem_read_data0,
    output        mem_read0,
    output        mem_write0,
    output [31:0] mem_addr0,
    output [31:0] mem_wdata0,
    output [2:0]  mem_funct30,
    output        mem_amo0,
    output [4:0]  mem_amo_op0,
    output        mem_amo_lr0,
    output        mem_amo_sc0,
    input  [31:0] mem_read_data1,
    output        mem_read1,
    output        mem_write1,
    output [31:0] mem_addr1,
    output [31:0] mem_wdata1,
    output [2:0]  mem_funct31,
    output [31:0] pc_out,
    output        reg_write0,
    output [4:0]  reg_wa0,
    output [31:0] reg_wd0,
    output        reg_write1,
    output [4:0]  reg_wa1,
    output [31:0] reg_wd1,
    output        ecall,
    output        halt
);

    wire stall_if, stall_id, flush_id, flush_ex, squash_s1;
    wire hz_stall_if, hz_stall_id, hz_flush_id, hz_flush_ex, hz_squash_s1;
    wire id_branch_redirect0;
    wire id_trap_fire, id_mret_fire, id_sret_fire, id_sfence_fire, id_fence_i_fire;
    wire [31:0] machine_trap_vector, machine_mepc, supervisor_mepc;
    wire [1:0] machine_privilege;
    wire [31:0] machine_mstatus, machine_sstatus, machine_mie, machine_mip, machine_mideleg;
    wire [1:0] retire_count;
    wire older_pipeline_busy, id_serial_drain_stall;
    wire [31:0] id_branch_target0;
    wire id_amo_accept;
    wire id_amo_drain_stall;
    wire [1:0] fwd_a0, fwd_b0;
    wire [2:0] fwd_a1, fwd_b1;

    // Freeze only IF/ID/EX once halt reaches EX/MEM.
    // Keep EX/MEM->MEM/WB advancing so halt can retire in WB.
    wire pipe_halt = ex_mem_halt0 || ex_mem_halt1;

    // =========================================================
    // IF
    // =========================================================
    wire [31:0] pc_current;
    wire [31:0] pc_plus4 = pc_current + 32'd4;
    wire [31:0] pc_plus8 = pc_current + 32'd8;
    wire [31:0] pc_next;
    reg atomic_lock;
    reg mem_wb_amo0;

    // Hybrid branch predictor on slot 0 fetch stream.
    localparam integer HYBP_IDX_BITS = 8;
    localparam integer HYBP_ENTRIES = (1 << HYBP_IDX_BITS);
    localparam integer HYBP_GHR_BITS = 8;

    localparam integer BTB_IDX_BITS = 8;
    localparam integer BTB_ENTRIES = (1 << BTB_IDX_BITS);
    localparam integer RAS_DEPTH = 16;
    localparam integer RAS_PTR_BITS = 4;
    localparam [RAS_PTR_BITS:0] RAS_DEPTH_COUNT = RAS_DEPTH;

    reg [1:0] hybp_local_pht  [0:HYBP_ENTRIES-1];
    reg [1:0] hybp_global_pht [0:HYBP_ENTRIES-1];
    reg [1:0] hybp_choice_pht [0:HYBP_ENTRIES-1];
    reg [HYBP_GHR_BITS-1:0] hybp_ghr;
    reg       btb_valid [0:BTB_ENTRIES-1];
    reg [31:0] btb_tag [0:BTB_ENTRIES-1];
    reg [31:0] btb_target [0:BTB_ENTRIES-1];
    reg [31:0] ras_stack [0:RAS_DEPTH-1];
    reg [RAS_PTR_BITS-1:0] ras_top_ptr;
    reg [RAS_PTR_BITS:0] ras_count;
    integer hybp_i;
    integer ras_i;

    wire [HYBP_IDX_BITS-1:0] if_pred_pc_idx = pc_current[9:2] ^ pc_current[15:8];
    wire if_is_branch0 = (instr0[6:0] == `OPCODE_BRANCH);
    wire if_is_jal0 = (instr0[6:0] == `OPCODE_JAL);
    wire if_is_jalr0 = (instr0[6:0] == `OPCODE_JALR);
    wire [4:0] if_rd0 = instr0[11:7];
    wire [4:0] if_rs1_0 = instr0[19:15];
    wire [31:0] if_branch_imm0 = {{19{instr0[31]}}, instr0[31], instr0[7], instr0[30:25], instr0[11:8], 1'b0};
    wire [31:0] if_jal_imm0 = {{11{instr0[31]}}, instr0[31], instr0[19:12], instr0[20], instr0[30:21], 1'b0};
    wire [31:0] if_jalr_imm0 = {{20{instr0[31]}}, instr0[31:20]};
    wire if_is_ret0 = if_is_jalr0 && (if_rd0 == 5'd0) &&
                      ((if_rs1_0 == 5'd1) || (if_rs1_0 == 5'd5)) && (if_jalr_imm0 == 32'd0);
    wire ras_has_entry0 = (ras_count != 0);
    wire [31:0] if_ras_target0 = ras_has_entry0 ? ras_stack[ras_top_ptr] : 32'b0;
    wire [BTB_IDX_BITS-1:0] if_btb_idx0 = pc_current[9:2];
    wire if_btb_hit0 = btb_valid[if_btb_idx0] && (btb_tag[if_btb_idx0] == pc_current);
    wire [HYBP_IDX_BITS-1:0] if_local_idx0 = if_pred_pc_idx;
    wire [HYBP_IDX_BITS-1:0] if_global_idx0 = if_pred_pc_idx ^ hybp_ghr[HYBP_IDX_BITS-1:0];
    wire if_local_pred_taken0 = hybp_local_pht[if_local_idx0][1];
    wire if_global_pred_taken0 = hybp_global_pht[if_global_idx0][1];
    wire if_choose_global0 = hybp_choice_pht[if_global_idx0][1];
    wire if_pred_branch_taken0 = if_choose_global0 ? if_global_pred_taken0 : if_local_pred_taken0;
    wire if_pred_jal_taken0 = if_is_jal0;
    wire if_pred_jalr_taken0 = if_is_jalr0 && (if_is_ret0 ? ras_has_entry0 : if_btb_hit0);
    wire if_pred_taken0 = (if_is_branch0 && if_pred_branch_taken0) || if_pred_jal_taken0 || if_pred_jalr_taken0;
    wire [31:0] if_pred_target0 = if_is_branch0 ? (if_btb_hit0 ? btb_target[if_btb_idx0] : (pc_current + if_branch_imm0)) :
                               if_is_jal0    ? (pc_current + if_jal_imm0) :
                               if_is_ret0    ? if_ras_target0 :
                                               btb_target[if_btb_idx0];

    pc_reg #(.RESET_PC(RESET_PC)) pc_counter (
        .clk    (clk),
        .rst    (rst),
        .stall  (stall_if || pipe_halt),
        .pc_next(pc_next),
        .pc     (pc_current)
    );

    assign pc_out = pc_current;

    // =========================================================
    // IF/ID
    // =========================================================
    reg [31:0] if_id_pc0, if_id_pc1;
    reg [31:0] if_id_instr0, if_id_instr1;
    reg        if_id_valid0, if_id_valid1;
    reg        if_id_pred_taken0;
    reg [31:0] if_id_pred_target0;
    reg [HYBP_IDX_BITS-1:0] if_id_local_idx0;
    reg [HYBP_IDX_BITS-1:0] if_id_global_idx0;
    reg        if_id_local_pred_taken0;
    reg        if_id_global_pred_taken0;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            if_id_pc0    <= 32'b0; if_id_pc1    <= 32'b0;
            if_id_instr0 <= 32'h0000_0013; if_id_instr1 <= 32'h0000_0013;
            if_id_valid0 <= 1'b0; if_id_valid1 <= 1'b0;
            if_id_pred_taken0 <= 1'b0;
            if_id_pred_target0 <= 32'b0;
            if_id_local_idx0 <= {HYBP_IDX_BITS{1'b0}};
            if_id_global_idx0 <= {HYBP_IDX_BITS{1'b0}};
            if_id_local_pred_taken0 <= 1'b0;
            if_id_global_pred_taken0 <= 1'b0;
        end else if (flush_id) begin
            if_id_pc0    <= 32'b0; if_id_pc1    <= 32'b0;
            if_id_instr0 <= 32'h0000_0013; if_id_instr1 <= 32'h0000_0013;
            if_id_valid0 <= 1'b0; if_id_valid1 <= 1'b0;
            if_id_pred_taken0 <= 1'b0;
            if_id_pred_target0 <= 32'b0;
            if_id_local_idx0 <= {HYBP_IDX_BITS{1'b0}};
            if_id_global_idx0 <= {HYBP_IDX_BITS{1'b0}};
            if_id_local_pred_taken0 <= 1'b0;
            if_id_global_pred_taken0 <= 1'b0;
        end else if (!stall_id && !pipe_halt) begin
            if_id_pc0    <= pc_current;
            if_id_pc1    <= pc_current + 32'd4;
            if_id_instr0 <= instr0;
            if_id_instr1 <= instr1;
            if_id_valid0 <= 1'b1;
            if_id_valid1 <= 1'b1;
            if_id_pred_taken0 <= if_pred_taken0;
            if_id_pred_target0 <= if_pred_target0;
            if_id_local_idx0 <= if_local_idx0;
            if_id_global_idx0 <= if_global_idx0;
            if_id_local_pred_taken0 <= if_local_pred_taken0;
            if_id_global_pred_taken0 <= if_global_pred_taken0;
        end
    end

    // =========================================================
    // ID — decode both slots
    // =========================================================
    wire [6:0] id_opcode0 = if_id_instr0[6:0];
    wire [2:0] id_funct30 = if_id_instr0[14:12];
    wire [6:0] id_funct70 = if_id_instr0[31:25];
    wire [4:0] id_rd0     = if_id_instr0[11:7];
    wire [4:0] id_rs1_0   = if_id_instr0[19:15];
    wire [4:0] id_rs2_0   = if_id_instr0[24:20];
    wire [11:0] id_csr0   = if_id_instr0[31:20];
    wire        id_amo0   = (id_opcode0 == `OPCODE_AMO);
    wire [4:0]  id_amo_op0 = if_id_instr0[31:27];
    wire        id_use_rs1_0 = (id_opcode0 == `OPCODE_AMO)    ||
                               (id_opcode0 == `OPCODE_LOAD)   ||
                               (id_opcode0 == `OPCODE_STORE)  ||
                               (id_opcode0 == `OPCODE_BRANCH) ||
                               (id_opcode0 == `OPCODE_JALR)   ||
                               (id_opcode0 == `OPCODE_OP_IMM) ||
                               (id_opcode0 == `OPCODE_OP)     ||
                               ((id_opcode0 == `OPCODE_CSR) && (id_funct30 != 3'b000) && !id_funct30[2]);
    wire        id_use_rs2_0 = (id_opcode0 == `OPCODE_AMO)    ||
                               (id_opcode0 == `OPCODE_STORE)  ||
                               (id_opcode0 == `OPCODE_BRANCH) ||
                               (id_opcode0 == `OPCODE_OP);

    wire id_mem_read0, id_mem_write0, id_reg_write0, id_mem_to_reg0;
    wire id_alu_src0, id_auipc0, id_is_lui0;
    wire [1:0] id_alu_op0;
    wire [2:0] id_imm_type0;
    wire id_branch0, id_jal0, id_jalr0, id_ecall0, id_ebreak0, id_mret0, id_sret0, id_sfence_vma0, id_wfi0, id_fence_i0, id_halt0;
    wire id_csr_read0, id_decode_csr_write0, id_csr_write0, id_decode_illegal0;
    wire id_illegal0;

    control ctrl0 (
        .opcode(id_opcode0), .funct3(id_funct30), .funct7(id_funct70), .system_imm(id_csr0), .rd(id_rd0),
        .mem_read(id_mem_read0), .mem_write(id_mem_write0),
        .reg_write(id_reg_write0), .mem_to_reg(id_mem_to_reg0),
        .alu_src(id_alu_src0), .alu_op(id_alu_op0),
        .auipc(id_auipc0), .is_lui(id_is_lui0), .imm_type(id_imm_type0),
        .branch(id_branch0), .jal(id_jal0), .jalr(id_jalr0),
        .ecall(id_ecall0), .ebreak(id_ebreak0), .mret(id_mret0), .sret(id_sret0), .sfence_vma(id_sfence_vma0), .wfi(id_wfi0),
        .fence_i(id_fence_i0), .halt(id_halt0),
        .csr_read(id_csr_read0), .csr_write(id_decode_csr_write0), .illegal(id_decode_illegal0)
    );

    wire [31:0] id_imm0_raw;
    imm_gen ig0 (.instr(if_id_instr0), .imm_type(id_imm_type0), .imm(id_imm0_raw));
    wire [31:0] id_imm0 = id_amo0 ? 32'b0 : id_imm0_raw;

    wire [6:0] id_opcode1 = if_id_instr1[6:0];
    wire [2:0] id_funct31 = if_id_instr1[14:12];
    wire [6:0] id_funct71 = if_id_instr1[31:25];
    wire [4:0] id_rd1_w   = if_id_instr1[11:7];
    wire [4:0] id_rs1_1   = if_id_instr1[19:15];
    wire [4:0] id_rs2_1   = if_id_instr1[24:20];
    wire [11:0] id_csr1   = if_id_instr1[31:20];
    wire        id_amo1   = (id_opcode1 == `OPCODE_AMO);
    wire [4:0]  id_amo_op1 = if_id_instr1[31:27];
    wire        id_use_rs1_1 = (id_opcode1 == `OPCODE_AMO)    ||
                               (id_opcode1 == `OPCODE_LOAD)   ||
                               (id_opcode1 == `OPCODE_STORE)  ||
                               (id_opcode1 == `OPCODE_BRANCH) ||
                               (id_opcode1 == `OPCODE_JALR)   ||
                               (id_opcode1 == `OPCODE_OP_IMM) ||
                               (id_opcode1 == `OPCODE_OP)     ||
                               ((id_opcode1 == `OPCODE_CSR) && (id_funct31 != 3'b000) && !id_funct31[2]);
    wire        id_use_rs2_1 = (id_opcode1 == `OPCODE_AMO)    ||
                               (id_opcode1 == `OPCODE_STORE)  ||
                               (id_opcode1 == `OPCODE_BRANCH) ||
                               (id_opcode1 == `OPCODE_OP);

    wire id_mem_read1, id_mem_write1, id_reg_write1, id_mem_to_reg1;
    wire id_alu_src1, id_auipc1, id_is_lui1;
    wire [1:0] id_alu_op1;
    wire [2:0] id_imm_type1;
    wire id_branch1, id_jal1, id_jalr1, id_ecall1, id_ebreak1, id_mret1, id_sret1, id_sfence_vma1, id_wfi1, id_fence_i1, id_halt1;
    wire id_csr_read1, id_decode_csr_write1, id_csr_write1, id_decode_illegal1;
    wire id_illegal1;

    control ctrl1 (
        .opcode(id_opcode1), .funct3(id_funct31), .funct7(id_funct71), .system_imm(id_csr1), .rd(id_rd1_w),
        .mem_read(id_mem_read1), .mem_write(id_mem_write1),
        .reg_write(id_reg_write1), .mem_to_reg(id_mem_to_reg1),
        .alu_src(id_alu_src1), .alu_op(id_alu_op1),
        .auipc(id_auipc1), .is_lui(id_is_lui1), .imm_type(id_imm_type1),
        .branch(id_branch1), .jal(id_jal1), .jalr(id_jalr1),
        .ecall(id_ecall1), .ebreak(id_ebreak1), .mret(id_mret1), .sret(id_sret1), .sfence_vma(id_sfence_vma1), .wfi(id_wfi1),
        .fence_i(id_fence_i1), .halt(id_halt1),
        .csr_read(id_csr_read1), .csr_write(id_decode_csr_write1), .illegal(id_decode_illegal1)
    );

    wire [31:0] id_imm1;
    imm_gen ig1 (.instr(if_id_instr1), .imm_type(id_imm_type1), .imm(id_imm1));

    // Only implemented CSRs are legal to access. Privilege is encoded in
    // address[9:8]; address[11:10]==2'b11 denotes an architecturally RO CSR.
    function csr_address_supported;
        input [11:0] csr_address;
        begin
            case (csr_address)
                `CSR_SSTATUS, `CSR_SIE, `CSR_STVEC, `CSR_SSCRATCH,
                `CSR_SEPC, `CSR_SCAUSE, `CSR_STVAL, `CSR_SIP, `CSR_SATP,
                `CSR_MEDELEG, `CSR_MIDELEG,
                `CSR_MSTATUS, `CSR_MISA, `CSR_MIE, `CSR_MTVEC,
                `CSR_MSCRATCH, `CSR_MEPC, `CSR_MCAUSE, `CSR_MTVAL, `CSR_MIP,
                `CSR_PMPCFG0, `CSR_PMPADDR0,
                `CSR_MCYCLE, `CSR_MINSTRET, `CSR_MCYCLEH, `CSR_MINSTRETH,
                `CSR_CYCLE, `CSR_TIME, `CSR_INSTRET,
                `CSR_CYCLEH, `CSR_TIMEH, `CSR_INSTRETH,
                `CSR_MVENDORID, `CSR_MARCHID, `CSR_MIMPID, `CSR_MHARTID:
                    csr_address_supported = 1'b1;
                default: csr_address_supported = 1'b0;
            endcase
        end
    endfunction

    wire id_csr_write_intent0 = id_decode_csr_write0 &&
        ((id_funct30 == 3'b001) || (id_funct30 == 3'b101) ||
         (((id_funct30 == 3'b010) || (id_funct30 == 3'b011)) && (id_rs1_0 != 5'b0)) ||
         (((id_funct30 == 3'b110) || (id_funct30 == 3'b111)) && (id_rs1_0 != 5'b0)));
    wire id_csr_write_intent1 = id_decode_csr_write1 &&
        ((id_funct31 == 3'b001) || (id_funct31 == 3'b101) ||
         (((id_funct31 == 3'b010) || (id_funct31 == 3'b011)) && (id_rs1_1 != 5'b0)) ||
         (((id_funct31 == 3'b110) || (id_funct31 == 3'b111)) && (id_rs1_1 != 5'b0)));
    assign id_csr_write0 = id_csr_write_intent0;
    assign id_csr_write1 = id_csr_write_intent1;
    wire id_csr_access_illegal0 = id_csr_read0 &&
        (!csr_address_supported(id_csr0) || (id_csr0[9:8] > machine_privilege) ||
         (id_csr_write_intent0 && (id_csr0[11:10] == 2'b11)));
    wire id_csr_access_illegal1 = id_csr_read1 &&
        (!csr_address_supported(id_csr1) || (id_csr1[9:8] > machine_privilege) ||
         (id_csr_write_intent1 && (id_csr1[11:10] == 2'b11)));
    assign id_illegal0 = id_decode_illegal0 || id_csr_access_illegal0 ||
                         (id_amo0 && (id_amo_op0 == 5'b00010) && (id_rs2_0 != 5'b0)) ||
                         (id_mret0 && (machine_privilege != 2'b11)) ||
                         ((id_sret0 || id_sfence_vma0) && (machine_privilege == 2'b00));
    assign id_illegal1 = id_decode_illegal1 || id_csr_access_illegal1 ||
                         (id_amo1 && (id_amo_op1 == 5'b00010) && (id_rs2_1 != 5'b0)) ||
                         (id_mret1 && (machine_privilege != 2'b11)) ||
                         ((id_sret1 || id_sfence_vma1) && (machine_privilege == 2'b00));

    wire id_is_rtype0 = (id_opcode0 == `OPCODE_OP);
    wire id_is_rtype1 = (id_opcode1 == `OPCODE_OP);
    wire id_mem_misaligned0, id_mem_misaligned1, id_s1_mem_addr_dep;
    wire id_inst_misaligned0, id_inst_misaligned1;
    wire id_s0_addr_wait;
    wire id_s0_csr = if_id_valid0 && id_csr_read0;
    wire id_s0_priv = if_id_valid0 &&
                      (id_illegal0 || id_ecall0 || id_ebreak0 || id_mret0 || id_sret0 || id_sfence_vma0 ||
                       id_inst_misaligned0 || (id_mem_misaligned0 && !id_s0_addr_wait));
    wire id_s1_priv = if_id_valid1 &&
                      (id_amo1 || id_illegal1 || id_ecall1 || id_ebreak1 || id_mret1 || id_sret1 || id_sfence_vma1 || id_fence_i1 ||
                       id_inst_misaligned1 ||
                       (TRAP_MISALIGNED && (id_mem_misaligned1 || id_s1_mem_addr_dep)));
    wire id_s0_serial = id_s0_csr || id_s0_priv ||
                        (if_id_valid0 && (id_fence_i0 || id_amo0));

    wire [31:0] id_rd1_raw0, id_rd2_raw0, id_rd1_raw1, id_rd2_raw1;

    registers #(.BOOT_A0(BOOT_A0), .BOOT_A1(BOOT_A1)) regs (
        .clk(clk), .rst(rst),
        .we0(reg_write0), .wa0(reg_wa0), .wd0(reg_wd0),
        .we1(reg_write1), .wa1(reg_wa1), .wd1(reg_wd1),
        .ra1(id_rs1_0), .rd1(id_rd1_raw0),
        .ra2(id_rs2_0), .rd2(id_rd2_raw0),
        .ra3(id_rs1_1), .rd3(id_rd1_raw1),
        .ra4(id_rs2_1), .rd4(id_rd2_raw1)
    );

    // WB→ID bypass
    wire [31:0] id_rd1_0 = (reg_write1 && reg_wa1 != 0 && reg_wa1 == id_rs1_0) ? reg_wd1 :
                           (reg_write0 && reg_wa0 != 0 && reg_wa0 == id_rs1_0) ? reg_wd0 :
                           id_rd1_raw0;
    wire [31:0] id_rd2_0 = (reg_write1 && reg_wa1 != 0 && reg_wa1 == id_rs2_0) ? reg_wd1 :
                           (reg_write0 && reg_wa0 != 0 && reg_wa0 == id_rs2_0) ? reg_wd0 :
                           id_rd2_raw0;
    wire [31:0] id_rd1_1 = (reg_write1 && reg_wa1 != 0 && reg_wa1 == id_rs1_1) ? reg_wd1 :
                           (reg_write0 && reg_wa0 != 0 && reg_wa0 == id_rs1_1) ? reg_wd0 :
                           id_rd1_raw1;
    wire [31:0] id_rd2_1 = (reg_write1 && reg_wa1 != 0 && reg_wa1 == id_rs2_1) ? reg_wd1 :
                           (reg_write0 && reg_wa0 != 0 && reg_wa0 == id_rs2_1) ? reg_wd0 :
                           id_rd2_raw1;

    // Inter-slot memory dependency check (luopt): only treat as dependency when
    // store/load widths match and low address bits alias.
    wire s0_is_store = id_mem_write0;
    wire s1_is_load = id_mem_read1;
    wire s0_store_word = s0_is_store && (id_funct30 == 3'b010);
    wire s0_store_half = s0_is_store && (id_funct30 == 3'b001);
    wire s0_store_byte = s0_is_store && (id_funct30 == 3'b000);
    wire s1_load_word = s1_is_load && (id_funct31 == 3'b010);
    wire s1_load_half = s1_is_load && ((id_funct31 == 3'b001) || (id_funct31 == 3'b101));
    wire s1_load_byte = s1_is_load && ((id_funct31 == 3'b000) || (id_funct31 == 3'b100));
    wire s0s1_addr_alias_w = (id_imm0[1:0] == id_imm1[1:0]);
    wire s0s1_addr_alias_h = (id_imm0[1] == id_imm1[1]);
    wire s0s1_addr_alias_b = 1'b1;
    wire s0_s1_mem_dep = (s0_store_word && s1_load_word && s0s1_addr_alias_w) ||
                         (s0_store_half && s1_load_half && s0s1_addr_alias_h) ||
                         (s0_store_byte && s1_load_byte && s0s1_addr_alias_b);

    // squash_s1: zero out all slot 1 control signals
    wire eff_id_mem_read1   = squash_s1 ? 1'b0 : id_mem_read1;
    wire eff_id_mem_write1  = squash_s1 ? 1'b0 : id_mem_write1;
    wire eff_id_reg_write1  = squash_s1 ? 1'b0 : id_reg_write1;
    wire eff_id_mem_to_reg1 = squash_s1 ? 1'b0 : id_mem_to_reg1;
    wire eff_id_alu_src1    = squash_s1 ? 1'b0 : id_alu_src1;
    wire [1:0] eff_id_alu_op1 = squash_s1 ? 2'b0 : id_alu_op1;
    wire eff_id_auipc1      = squash_s1 ? 1'b0 : id_auipc1;
    wire eff_id_is_lui1     = squash_s1 ? 1'b0 : id_is_lui1;
    wire eff_id_branch1     = squash_s1 ? 1'b0 : id_branch1;
    wire eff_id_jal1        = squash_s1 ? 1'b0 : id_jal1;
    wire eff_id_jalr1       = squash_s1 ? 1'b0 : id_jalr1;
    wire eff_id_ecall1      = squash_s1 ? 1'b0 : id_ecall1;
    wire eff_id_halt1       = squash_s1 ? 1'b0 : id_halt1;
    wire eff_id_csr_read1   = squash_s1 ? 1'b0 : id_csr_read1;
    wire eff_id_csr_write1  = squash_s1 ? 1'b0 : id_csr_write1;
    wire eff_id_is_rtype1   = squash_s1 ? 1'b0 : id_is_rtype1;
    wire [4:0] eff_id_rd1   = squash_s1 ? 5'b0 : id_rd1_w;

    // =========================================================
    // ID/EX — slot 0
    // =========================================================
    reg [31:0] id_ex_pc0, id_ex_rd1_0, id_ex_rd2_0, id_ex_imm0;
    reg [4:0]  id_ex_rs1_0, id_ex_rs2_0, id_ex_rd0;
    reg [2:0]  id_ex_funct3_0;
    reg [6:0]  id_ex_funct7_0;
    reg [11:0] id_ex_csr0;
    reg        id_ex_mem_read0, id_ex_mem_write0, id_ex_reg_write0, id_ex_mem_to_reg0;
    reg        id_ex_alu_src0, id_ex_auipc0, id_ex_is_lui0;
    reg [1:0]  id_ex_alu_op0;
    reg        id_ex_branch0, id_ex_jal0, id_ex_jalr0;
    reg        id_ex_ecall0, id_ex_halt0, id_ex_csr_read0, id_ex_csr_write0;
    reg        id_ex_is_rtype0;
    reg        id_ex_amo0;
    reg        id_ex_valid0;
    reg        id_ex_pred_taken0;
    reg [HYBP_IDX_BITS-1:0] id_ex_local_idx0;
    reg [HYBP_IDX_BITS-1:0] id_ex_global_idx0;
    reg        id_ex_local_pred_taken0;
    reg        id_ex_global_pred_taken0;

    always @(posedge clk or posedge rst) begin
        // Trap entry keeps older ID/EX work moving into EX/MEM, while the
        // instruction that raised the trap (still in IF/ID) becomes a bubble.
        if (rst || flush_ex || id_trap_fire) begin
            id_ex_pc0 <= 0; id_ex_rd1_0 <= 0; id_ex_rd2_0 <= 0; id_ex_imm0 <= 0;
            id_ex_rs1_0 <= 0; id_ex_rs2_0 <= 0; id_ex_rd0 <= 0;
            id_ex_funct3_0 <= 0; id_ex_funct7_0 <= 0; id_ex_csr0 <= 0;
            id_ex_mem_read0 <= 0; id_ex_mem_write0 <= 0; id_ex_reg_write0 <= 0;
            id_ex_mem_to_reg0 <= 0; id_ex_alu_src0 <= 0; id_ex_alu_op0 <= 0;
            id_ex_auipc0 <= 0; id_ex_is_lui0 <= 0; id_ex_branch0 <= 0;
            id_ex_jal0 <= 0; id_ex_jalr0 <= 0; id_ex_ecall0 <= 0;
            id_ex_halt0 <= 0; id_ex_csr_read0 <= 0; id_ex_csr_write0 <= 0;
            id_ex_is_rtype0 <= 0;
            id_ex_amo0 <= 0;
            id_ex_valid0 <= 0;
            id_ex_pred_taken0 <= 1'b0;
            id_ex_local_idx0 <= {HYBP_IDX_BITS{1'b0}};
            id_ex_global_idx0 <= {HYBP_IDX_BITS{1'b0}};
            id_ex_local_pred_taken0 <= 1'b0;
            id_ex_global_pred_taken0 <= 1'b0;
        end else if (!pipe_halt) begin
            id_ex_pc0         <= if_id_pc0;
            id_ex_rd1_0       <= id_rd1_0;
            id_ex_rd2_0       <= id_rd2_0;
            id_ex_imm0        <= id_imm0;
            id_ex_rs1_0       <= id_rs1_0;
            id_ex_rs2_0       <= id_rs2_0;
            id_ex_rd0         <= id_rd0;
            id_ex_funct3_0    <= id_funct30;
            id_ex_funct7_0    <= id_funct70;
            id_ex_csr0        <= id_csr0;
            id_ex_mem_read0   <= id_mem_read0;
            id_ex_mem_write0  <= id_mem_write0;
            id_ex_reg_write0  <= id_reg_write0;
            id_ex_mem_to_reg0 <= id_mem_to_reg0;
            id_ex_alu_src0    <= id_alu_src0;
            id_ex_alu_op0     <= id_alu_op0;
            id_ex_auipc0      <= id_auipc0;
            id_ex_is_lui0     <= id_is_lui0;
            // Branches are resolved early in ID (slot 0 path).
            id_ex_branch0     <= 1'b0;
            id_ex_jal0        <= id_jal0;
            id_ex_jalr0       <= id_jalr0;
            id_ex_ecall0      <= id_ecall0;
            id_ex_halt0       <= id_halt0 && ECALL_HALT;
            id_ex_csr_read0   <= id_csr_read0;
            id_ex_csr_write0  <= id_csr_write0;
            id_ex_is_rtype0   <= id_is_rtype0;
            id_ex_amo0        <= id_amo0 && !id_illegal0;
            id_ex_valid0      <= if_id_valid0;
            id_ex_pred_taken0 <= if_id_pred_taken0;
            id_ex_local_idx0 <= if_id_local_idx0;
            id_ex_global_idx0 <= if_id_global_idx0;
            id_ex_local_pred_taken0 <= if_id_local_pred_taken0;
            id_ex_global_pred_taken0 <= if_id_global_pred_taken0;
        end
    end

    // =========================================================
    // ID/EX — slot 1
    // =========================================================
    reg [31:0] id_ex_pc1, id_ex_rd1_1, id_ex_rd2_1, id_ex_imm1;
    reg [4:0]  id_ex_rs1_1, id_ex_rs2_1, id_ex_rd1;
    reg [2:0]  id_ex_funct3_1;
    reg [6:0]  id_ex_funct7_1;
    reg [11:0] id_ex_csr1;
    reg        id_ex_mem_read1, id_ex_mem_write1, id_ex_reg_write1, id_ex_mem_to_reg1;
    reg        id_ex_alu_src1, id_ex_auipc1, id_ex_is_lui1;
    reg [1:0]  id_ex_alu_op1;
    reg        id_ex_branch1, id_ex_jal1, id_ex_jalr1;
    reg        id_ex_ecall1, id_ex_halt1, id_ex_csr_read1, id_ex_csr_write1;
    reg        id_ex_is_rtype1;
    reg        id_ex_valid1;

    always @(posedge clk or posedge rst) begin
        if (rst || flush_ex || id_trap_fire) begin
            id_ex_pc1 <= 0; id_ex_rd1_1 <= 0; id_ex_rd2_1 <= 0; id_ex_imm1 <= 0;
            id_ex_rs1_1 <= 0; id_ex_rs2_1 <= 0; id_ex_rd1 <= 0;
            id_ex_funct3_1 <= 0; id_ex_funct7_1 <= 0; id_ex_csr1 <= 0;
            id_ex_mem_read1 <= 0; id_ex_mem_write1 <= 0; id_ex_reg_write1 <= 0;
            id_ex_mem_to_reg1 <= 0; id_ex_alu_src1 <= 0; id_ex_alu_op1 <= 0;
            id_ex_auipc1 <= 0; id_ex_is_lui1 <= 0; id_ex_branch1 <= 0;
            id_ex_jal1 <= 0; id_ex_jalr1 <= 0; id_ex_ecall1 <= 0;
            id_ex_halt1 <= 0; id_ex_csr_read1 <= 0; id_ex_csr_write1 <= 0;
            id_ex_is_rtype1 <= 0;
            id_ex_valid1 <= 0;
        end else if (!pipe_halt) begin
            id_ex_pc1         <= if_id_pc1;
            id_ex_rd1_1       <= id_rd1_1;
            id_ex_rd2_1       <= id_rd2_1;
            id_ex_imm1        <= id_imm1;
            id_ex_rs1_1       <= id_rs1_1;
            id_ex_rs2_1       <= id_rs2_1;
            id_ex_rd1         <= eff_id_rd1;
            id_ex_funct3_1    <= id_funct31;
            id_ex_funct7_1    <= id_funct71;
            id_ex_csr1        <= id_csr1;
            id_ex_mem_read1   <= eff_id_mem_read1;
            id_ex_mem_write1  <= eff_id_mem_write1;
            id_ex_reg_write1  <= eff_id_reg_write1;
            id_ex_mem_to_reg1 <= eff_id_mem_to_reg1;
            id_ex_alu_src1    <= eff_id_alu_src1;
            id_ex_alu_op1     <= eff_id_alu_op1;
            id_ex_auipc1      <= eff_id_auipc1;
            id_ex_is_lui1     <= eff_id_is_lui1;
            id_ex_branch1     <= eff_id_branch1;
            id_ex_jal1        <= eff_id_jal1;
            id_ex_jalr1       <= eff_id_jalr1;
            id_ex_ecall1      <= eff_id_ecall1;
            id_ex_halt1       <= eff_id_halt1 && ECALL_HALT;
            id_ex_csr_read1   <= eff_id_csr_read1;
            id_ex_csr_write1  <= eff_id_csr_write1;
            id_ex_is_rtype1   <= eff_id_is_rtype1;
            id_ex_valid1      <= if_id_valid1 && !squash_s1;
        end
    end

    // =========================================================
    // EX — forwarding data buses (declared early, driven later)
    // =========================================================
    wire [31:0] ex_mem_fwd_val0, ex_mem_fwd_val1;
    wire [31:0] mem_wb_fwd_val0, mem_wb_fwd_val1;

    // =========================================================
    // EX — slot 0 MEM/WB mux disambiguation
    // =========================================================
    // forward.v encodes both s0_mem_wb and s1_mem_wb hits as 2'b01.
    // Slot 1 is younger than slot 0 inside a pair, so it has priority when both match.
    wire [31:0] mem_wb_sel_s0_rs1 = (mem_wb_reg_write1 && mem_wb_rd1 != 0 &&
                                       mem_wb_rd1 == id_ex_rs1_0) ? mem_wb_fwd_val1
                                                                   : mem_wb_fwd_val0;
    wire [31:0] mem_wb_sel_s0_rs2 = (mem_wb_reg_write1 && mem_wb_rd1 != 0 &&
                                       mem_wb_rd1 == id_ex_rs2_0) ? mem_wb_fwd_val1
                                                                   : mem_wb_fwd_val0;

    wire [31:0] ex_rs1_fwd0 = (fwd_a0 == 2'b10) ? ex_mem_fwd_val0   :
                               (fwd_a0 == 2'b11) ? ex_mem_fwd_val1   :
                               (fwd_a0 == 2'b01) ? mem_wb_sel_s0_rs1 : id_ex_rd1_0;
    wire [31:0] ex_rs2_fwd0 = (fwd_b0 == 2'b10) ? ex_mem_fwd_val0   :
                               (fwd_b0 == 2'b11) ? ex_mem_fwd_val1   :
                               (fwd_b0 == 2'b01) ? mem_wb_sel_s0_rs2 : id_ex_rd2_0;

    wire [31:0] ex_alu_a0 = id_ex_auipc0  ? id_ex_pc0  :
                            id_ex_is_lui0 ? 32'b0      : ex_rs1_fwd0;
    wire [31:0] ex_alu_b0 = id_ex_alu_src0 ? id_ex_imm0 : ex_rs2_fwd0;

    wire ex_is_shift0  = (id_ex_alu_op0 == 2'b10) && (id_ex_funct3_0 == 3'b101);
    wire ex_funct7_5_0 = (ex_is_shift0 || id_ex_is_rtype0) ? id_ex_funct7_0[5] : 1'b0;

    wire [4:0] ex_alu_ctrl0;
    alu_ctrl ac0 (.alu_op(id_ex_alu_op0), .funct3(id_ex_funct3_0),
                  .funct7(id_ex_funct7_0), .funct7_5(ex_funct7_5_0),
                  .is_rtype(id_ex_is_rtype0),
                  .is_lui(id_ex_is_lui0), .alu_ctrl(ex_alu_ctrl0));

    wire [31:0] ex_alu_result0;
    wire        ex_alu_zero0;
    alu alu0 (.a(ex_alu_a0), .b(ex_alu_b0), .alu_op(ex_alu_ctrl0),
              .result(ex_alu_result0), .zero(ex_alu_zero0));

    wire ex_branch_taken0;
    branch_compare bc0 (.rs1(ex_rs1_fwd0), .rs2(ex_rs2_fwd0),
                        .funct3(id_ex_funct3_0), .branch_taken(ex_branch_taken0));

    // Slot-0 control flow is resolved and recovered in ID. A second EX-stage
    // flush/redirect for the same branch could discard the already-fetched
    // target pair, especially when an interrupt is draining the pipeline.
    wire ex_take_branch0 = 1'b0;
    wire ex_branch_mispredict0 = 1'b0;
    wire [31:0] ex_branch_target0 = id_ex_pc0 + id_ex_imm0;
    wire [31:0] ex_branch_recover_pc0 = ex_branch_taken0 ? ex_branch_target0 : (id_ex_pc0 + 32'd4);
    wire ex_redirect0 = 1'b0;
    wire [31:0] ex_redirect_pc0 = ex_branch_recover_pc0;

    wire [31:0] ex_link0 = id_ex_pc0 + 32'd4;
    wire [31:0] ex_csr_rdata0;

    wire [31:0] ex_wb_val0 = id_ex_csr_read0             ? ex_csr_rdata0 :
                             (id_ex_jal0 || id_ex_jalr0) ? ex_link0      :
                             ex_alu_result0;

    // =========================================================
    // EX — slot 1 MEM/WB mux disambiguation
    // =========================================================
    // Same principle: forward.v encodes both s0_mem_wb and s1_mem_wb hits as 3'b001.
    // Slot 1 is younger than slot 0 inside a pair, so it has priority when both match.
    wire [31:0] mem_wb_sel_s1_rs1 = (mem_wb_reg_write1 && mem_wb_rd1 != 0 &&
                                       mem_wb_rd1 == id_ex_rs1_1) ? mem_wb_fwd_val1
                                                                   : mem_wb_fwd_val0;
    wire [31:0] mem_wb_sel_s1_rs2 = (mem_wb_reg_write1 && mem_wb_rd1 != 0 &&
                                       mem_wb_rd1 == id_ex_rs2_1) ? mem_wb_fwd_val1
                                                                   : mem_wb_fwd_val0;

    wire [31:0] ex_rs1_fwd1 = (fwd_a1 == 3'b100) ? ex_wb_val0        :
                               (fwd_a1 == 3'b010) ? ex_mem_fwd_val0   :
                               (fwd_a1 == 3'b011) ? ex_mem_fwd_val1   :
                               (fwd_a1 == 3'b001) ? mem_wb_sel_s1_rs1 : id_ex_rd1_1;
    wire [31:0] ex_rs2_fwd1 = (fwd_b1 == 3'b100) ? ex_wb_val0        :
                               (fwd_b1 == 3'b010) ? ex_mem_fwd_val0   :
                               (fwd_b1 == 3'b011) ? ex_mem_fwd_val1   :
                               (fwd_b1 == 3'b001) ? mem_wb_sel_s1_rs2 : id_ex_rd2_1;

    // CSR/system side effects use one architectural state bank. A slot-0 CSR
    // serializes slot 1 in ID; slot-1 CSR is allowed only alongside an ordinary
    // slot-0 instruction, so at most one CSR reaches this shared port per cycle.
    wire id_has_csr = (if_id_valid0 && (id_csr_read0 || id_csr_write0)) ||
                      (if_id_valid1 && (id_csr_read1 || id_csr_write1));
    wire id_has_priv = (if_id_valid0 && (id_illegal0 || id_ecall0 || id_ebreak0 || id_mret0 || id_sret0 || id_sfence_vma0 || id_fence_i0)) ||
                       (if_id_valid1 && (id_illegal1 || id_ecall1 || id_ebreak1 || id_mret1 || id_sret1 || id_sfence_vma1 || id_fence_i1));
    wire ex_has_csr = (id_ex_valid0 && (id_ex_csr_read0 || id_ex_csr_write0)) ||
                      (id_ex_valid1 && (id_ex_csr_read1 || id_ex_csr_write1));
    // A system-state update must not race an older CSR write in EX. Hold decode
    // for one cycle so the older single-port CSR update becomes visible first.
    wire csr_hazard_stall = (id_has_csr || id_has_priv) && ex_has_csr;

    wire csr_active0 = id_ex_valid0 && (id_ex_csr_read0 || id_ex_csr_write0);
    wire csr_active1 = id_ex_valid1 && (id_ex_csr_read1 || id_ex_csr_write1);
    wire csr_select1 = !csr_active0 && csr_active1;
    wire [11:0] csr_addr = csr_select1 ? id_ex_csr1 : id_ex_csr0;
    wire [2:0] csr_funct3 = csr_select1 ? id_ex_funct3_1 : id_ex_funct3_0;
    wire [31:0] csr_source0 = id_ex_funct3_0[2] ? {27'b0, id_ex_rs1_0} : ex_rs1_fwd0;
    wire [31:0] csr_source1 = id_ex_funct3_1[2] ? {27'b0, id_ex_rs1_1} : ex_rs1_fwd1;
    wire [31:0] csr_wdata = csr_select1 ? csr_source1 : csr_source0;
    wire csr_we = csr_select1 ? id_ex_csr_write1 :
                  csr_active0 ? id_ex_csr_write0 : 1'b0;
    wire [31:0] csr_rdata;

    csr_reg csr_file (
        .clk(clk), .rst(rst), .timer_irq(timer_irq), .we(csr_we), .addr(csr_addr),
        .wdata(csr_wdata), .funct3(csr_funct3),
        .retire_count(retire_count),
        .trap_enter(id_trap_fire), .trap_pc(if_id_pc0),
        .trap_cause(id_illegal0 ? 32'd2 :
                    id_ebreak0 ? 32'd3 :
                    id_inst_misaligned0 ? 32'd0 :
                    id_mem_misaligned0 ? (id_mem_write0 ? 32'd6 : 32'd4) :
                    (id_ecall0 && !ECALL_HALT) ?
                        ((machine_privilege == 2'b00) ? 32'd8 :
                         (machine_privilege == 2'b01) ? 32'd9 : 32'd11) :
                    id_irq_m_external ? 32'h8000_000b :
                    id_irq_m_software ? 32'h8000_0003 :
                    id_irq_m_timer ? 32'h8000_0007 :
                    id_irq_s_external ? 32'h8000_0009 :
                    id_irq_s_software ? 32'h8000_0001 :
                    id_irq_s_timer ? 32'h8000_0005 : 32'd11),
        .trap_value(id_illegal0 ? if_id_instr0 :
                    id_inst_misaligned0 ? id_actual_pc0 :
                    id_mem_misaligned0 ? id_mem_addr0 : 32'b0),
        .trap_return(id_mret_fire), .trap_return_s(id_sret_fire),
        .rdata(csr_rdata), .trap_vector(machine_trap_vector),
        .mepc_value(machine_mepc), .sepc_value(supervisor_mepc),
        .privilege_mode(machine_privilege), .mstatus_value(machine_mstatus),
        .sstatus_value(machine_sstatus), .mie_value(machine_mie),
        .mip_value(machine_mip), .mideleg_value(machine_mideleg)
    );
    assign ex_csr_rdata0 = csr_rdata;
    assign ex_csr_rdata1 = csr_rdata;

    wire [31:0] ex_alu_a1 = id_ex_auipc1  ? id_ex_pc1  :
                            id_ex_is_lui1 ? 32'b0      : ex_rs1_fwd1;
    wire [31:0] ex_alu_b1 = id_ex_alu_src1 ? id_ex_imm1 : ex_rs2_fwd1;

    wire ex_is_shift1  = (id_ex_alu_op1 == 2'b10) && (id_ex_funct3_1 == 3'b101);
    wire ex_funct7_5_1 = (ex_is_shift1 || id_ex_is_rtype1) ? id_ex_funct7_1[5] : 1'b0;

    wire [4:0] ex_alu_ctrl1;
    alu_ctrl ac1 (.alu_op(id_ex_alu_op1), .funct3(id_ex_funct3_1),
                  .funct7(id_ex_funct7_1), .funct7_5(ex_funct7_5_1),
                  .is_rtype(id_ex_is_rtype1),
                  .is_lui(id_ex_is_lui1), .alu_ctrl(ex_alu_ctrl1));

    wire [31:0] ex_alu_result1;
    wire        ex_alu_zero1;
    alu alu1 (.a(ex_alu_a1), .b(ex_alu_b1), .alu_op(ex_alu_ctrl1),
              .result(ex_alu_result1), .zero(ex_alu_zero1));

    wire ex_branch_taken1;
    branch_compare bc1 (.rs1(ex_rs1_fwd1), .rs2(ex_rs2_fwd1),
                        .funct3(id_ex_funct3_1), .branch_taken(ex_branch_taken1));

    wire ex_take_branch1 = id_ex_branch1 && ex_branch_taken1;

    wire [31:0] ex_link1 = id_ex_pc1 + 32'd4;
    wire [31:0] ex_csr_rdata1;

    wire [31:0] ex_wb_val1 = id_ex_csr_read1             ? ex_csr_rdata1 :
                             (id_ex_jal1 || id_ex_jalr1) ? ex_link1      :
                             ex_alu_result1;

    // =========================================================
    // ID branch resolution (early, slot 0)
    // =========================================================
    wire id0_dep_ex1_rs1 = id_ex_reg_write1 && (id_ex_rd1 != 5'b0) && (id_ex_rd1 == id_rs1_0);
    wire id0_dep_ex1_rs2 = id_ex_reg_write1 && (id_ex_rd1 != 5'b0) && (id_ex_rd1 == id_rs2_0);
    wire id0_dep_ex0_rs1 = id_ex_reg_write0 && (id_ex_rd0 != 5'b0) && (id_ex_rd0 == id_rs1_0);
    wire id0_dep_ex0_rs2 = id_ex_reg_write0 && (id_ex_rd0 != 5'b0) && (id_ex_rd0 == id_rs2_0);

    wire id0_dep_mem1_rs1 = ex_mem_reg_write1 && (ex_mem_rd1 != 5'b0) && (ex_mem_rd1 == id_rs1_0);
    wire id0_dep_mem1_rs2 = ex_mem_reg_write1 && (ex_mem_rd1 != 5'b0) && (ex_mem_rd1 == id_rs2_0);
    wire id0_dep_mem0_rs1 = ex_mem_reg_write0 && (ex_mem_rd0 != 5'b0) && (ex_mem_rd0 == id_rs1_0);
    wire id0_dep_mem0_rs2 = ex_mem_reg_write0 && (ex_mem_rd0 != 5'b0) && (ex_mem_rd0 == id_rs2_0);

    wire [31:0] id_mem_fwd_val0 = ex_mem_mem_to_reg0 ? mem_read_data0 : ex_mem_wb0;
    wire [31:0] id_mem_fwd_val1 = ex_mem_mem_to_reg1 ? mem_read_data1 : ex_mem_wb1;

    wire [31:0] id_branch_rs1_0 = (id0_dep_ex1_rs1 && !id_ex_mem_read1) ? ex_wb_val1    :
                                  (id0_dep_ex0_rs1 && !id_ex_mem_read0) ? ex_wb_val0    :
                                  (id0_dep_mem1_rs1)                    ? id_mem_fwd_val1 :
                                  (id0_dep_mem0_rs1)                    ? id_mem_fwd_val0 :
                                                                           id_rd1_0;
    wire [31:0] id_branch_rs2_0 = (id0_dep_ex1_rs2 && !id_ex_mem_read1) ? ex_wb_val1    :
                                  (id0_dep_ex0_rs2 && !id_ex_mem_read0) ? ex_wb_val0    :
                                  (id0_dep_mem1_rs2)                    ? id_mem_fwd_val1 :
                                  (id0_dep_mem0_rs2)                    ? id_mem_fwd_val0 :
                                                                           id_rd2_0;

    wire [31:0] id_mem_addr0 = id_branch_rs1_0 + id_imm0;
    wire [31:0] id_mem_addr1 = id_rd1_1 + id_imm1;
    assign id_mem_misaligned0 = TRAP_MISALIGNED && if_id_valid0 &&
        (id_mem_read0 || id_mem_write0) &&
        (((id_funct30 == 3'b001 || id_funct30 == 3'b101) && id_mem_addr0[0]) ||
         (id_funct30 == 3'b010 && (|id_mem_addr0[1:0])));
    assign id_mem_misaligned1 = TRAP_MISALIGNED && if_id_valid1 &&
        (id_mem_read1 || id_mem_write1) &&
        (((id_funct31 == 3'b001 || id_funct31 == 3'b101) && id_mem_addr1[0]) ||
         (id_funct31 == 3'b010 && (|id_mem_addr1[1:0])));

    // A slot-1 memory op that depends on a not-yet-committed older result is
    // replayed as slot 0. Slot 0 has the complete forwarding and load-wait
    // machinery needed to test the true effective address without degrading
    // independent memory pairs.
    assign id_s1_mem_addr_dep = (id_mem_read1 || id_mem_write1) &&
        ((if_id_valid0 && id_reg_write0 && (id_rd0 != 5'b0) && (id_rd0 == id_rs1_1)) ||
         (id_ex_valid0 && id_ex_reg_write0 && (id_ex_rd0 != 5'b0) && (id_ex_rd0 == id_rs1_1)) ||
         (id_ex_valid1 && id_ex_reg_write1 && (id_ex_rd1 != 5'b0) && (id_ex_rd1 == id_rs1_1)) ||
         (ex_mem_valid0 && ex_mem_reg_write0 && (ex_mem_rd0 != 5'b0) && (ex_mem_rd0 == id_rs1_1)) ||
         (ex_mem_valid1 && ex_mem_reg_write1 && (ex_mem_rd1 != 5'b0) && (ex_mem_rd1 == id_rs1_1)));

    assign id_s0_addr_wait = TRAP_MISALIGNED && if_id_valid0 && (id_mem_read0 || id_mem_write0) &&
        ((id_ex_valid0 && id_ex_mem_read0 && (id_ex_rd0 != 5'b0) && (id_ex_rd0 == id_rs1_0)) ||
         (id_ex_valid1 && id_ex_mem_read1 && (id_ex_rd1 != 5'b0) && (id_ex_rd1 == id_rs1_0)));

    wire id_branch_taken0_id;
    branch_compare id_br_cmp0 (
        .rs1         (id_branch_rs1_0),
        .rs2         (id_branch_rs2_0),
        .funct3      (id_funct30),
        .branch_taken(id_branch_taken0_id)
    );

    wire [31:0] id_branch_fallthrough0 = if_id_pc0 + 32'd4;
    wire [31:0] id_jal_target0 = if_id_pc0 + id_imm0;
    wire [31:0] id_jalr_target0 = (id_branch_rs1_0 + id_imm0) & ~32'd1;
    wire id_is_ret0 = id_jalr0 && (id_rd0 == 5'd0) &&
                      ((id_rs1_0 == 5'd1) || (id_rs1_0 == 5'd5)) && (id_imm0 == 32'd0);
    wire id_is_call0 = (id_jal0 || id_jalr0) && ((id_rd0 == 5'd1) || (id_rd0 == 5'd5)) && !id_is_ret0;

    wire [31:0] id_expected_pc0 = if_id_pred_taken0 ? if_id_pred_target0 : id_branch_fallthrough0;
    wire [31:0] id_actual_pc0 = id_branch0 ? (id_branch_taken0_id ? (if_id_pc0 + id_imm0) : id_branch_fallthrough0) :
                               id_jal0    ? id_jal_target0 :
                               id_jalr0   ? id_jalr_target0 :
                                            id_branch_fallthrough0;
    wire [31:0] id_direct_target1 = if_id_pc1 + id_imm1;
    assign id_inst_misaligned0 = TRAP_INST_MISALIGNED && if_id_valid0 && !hz_stall_id &&
        ((id_jal0 || id_jalr0 || (id_branch0 && id_branch_taken0_id)) && (|id_actual_pc0[1:0]));
    // Slot-1 control transfers are replayed when their target may violate the
    // RV32I four-byte instruction alignment, then checked precisely in slot 0.
    assign id_inst_misaligned1 = TRAP_INST_MISALIGNED && if_id_valid1 &&
        (id_jalr1 || ((id_jal1 || id_branch1) && (|id_direct_target1[1:0])));

    assign id_branch_target0   = id_actual_pc0;
    assign id_branch_redirect0 = if_id_valid0 && (id_branch0 || id_jal0 || id_jalr0) &&
                                 !hz_stall_id && !id_inst_misaligned0 &&
                                 (id_expected_pc0 != id_actual_pc0);

    // Machine interrupt priority is MEI > MSI > MTI > SEI > SSI > STI.
    wire id_irq_m_global = (machine_privilege != 2'b11) || machine_mstatus[3];
    wire id_irq_s_global = (machine_privilege == 2'b00) ||
                           ((machine_privilege == 2'b01) && machine_mstatus[1]);
    wire id_irq_m_external = id_irq_m_global && machine_mip[11] && machine_mie[11] && !machine_mideleg[11];
    wire id_irq_m_software = id_irq_m_global && machine_mip[3]  && machine_mie[3]  && !machine_mideleg[3];
    wire id_irq_m_timer    = id_irq_m_global && machine_mip[7]  && machine_mie[7]  && !machine_mideleg[7];
    wire id_irq_s_external = id_irq_s_global && machine_mip[9]  && machine_mie[9]  && machine_mideleg[9];
    wire id_irq_s_software = id_irq_s_global && machine_mip[1]  && machine_mie[1]  && machine_mideleg[1];
    wire id_irq_s_timer    = id_irq_s_global && machine_mip[5]  && machine_mie[5]  && machine_mideleg[5];
    // Defer asynchronous interrupt entry across a control-transfer in ID.
    // That instruction's redirect/squash is resolved first; the pending IRQ is
    // then taken at the next clean instruction boundary.
    wire id_interrupt_candidate = if_id_valid0 &&
        !(id_branch0 || id_jal0 || id_jalr0) &&
        (id_irq_m_external || id_irq_m_software || id_irq_m_timer ||
         id_irq_s_external || id_irq_s_software || id_irq_s_timer);

    // An older control redirect in EX wins over a younger ID-stage system event.
    wire older_redirect_pending = ex_redirect0 || ex_take_branch1 || id_ex_jal1 || id_ex_jalr1;
    wire id_trap_candidate = if_id_valid0 &&
                             (id_illegal0 || id_ebreak0 || id_inst_misaligned0 ||
                              (id_mem_misaligned0 && !id_s0_addr_wait) ||
                              (id_ecall0 && !ECALL_HALT) || id_interrupt_candidate);
    wire id_mret_candidate = if_id_valid0 && id_mret0 && !id_illegal0;
    wire id_sret_candidate = if_id_valid0 && id_sret0 && !id_illegal0;
    wire id_sfence_candidate = if_id_valid0 && id_sfence_vma0 && !id_illegal0;
    wire id_fence_i_candidate = if_id_valid0 && id_fence_i0;
    wire id_serial_event_candidate = id_trap_candidate || id_mret_candidate ||
                                     id_sret_candidate || id_sfence_candidate || id_fence_i_candidate;

    // ID-stage traps, returns, and FENCE.I are held until every older pipeline
    // instruction has committed. Flush only the ID/EX input while draining;
    // EX/MEM and MEM/WB continue to advance so older stores/writes take effect.
    assign id_serial_drain_stall = id_serial_event_candidate &&
                                   !older_redirect_pending && older_pipeline_busy;
    assign id_trap_fire = id_trap_candidate && !csr_hazard_stall &&
                          !older_redirect_pending && !older_pipeline_busy;
    assign id_mret_fire = id_mret_candidate && !csr_hazard_stall &&
                          !older_redirect_pending && !older_pipeline_busy;
    assign id_sret_fire = id_sret_candidate && !csr_hazard_stall &&
                          !older_redirect_pending && !older_pipeline_busy;
    assign id_sfence_fire = id_sfence_candidate && !csr_hazard_stall &&
                             !older_redirect_pending && !older_pipeline_busy;
    assign id_fence_i_fire = id_fence_i_candidate && !csr_hazard_stall &&
                             !older_redirect_pending && !older_pipeline_busy;

    // PC mux — older EX redirects have priority; traps/returns then restart at
    // the architectural vector/EPC, before any fetch replay.
    // squash_s1 is decided in ID for if_id_pc0/if_id_pc1 while pc_current is already
    // one fetch group ahead, so replay from if_id_pc0+4 (single-issue fallback).
    wire [31:0] squash_replay_pc = if_id_pc0 + 32'd4;
    wire id_pred_taken_ctrl0 = if_id_valid0 && (id_branch0 || id_jal0 || id_jalr0) && if_id_pred_taken0;
    wire squash_replay_en = squash_s1 && !id_pred_taken_ctrl0;
    assign pc_next = ex_redirect0    ? ex_redirect_pc0                        :
                     ex_take_branch1 ? (id_ex_pc1 + id_ex_imm1)             :
                     id_ex_jal1      ? (id_ex_pc1 + id_ex_imm1)             :
                     id_ex_jalr1     ? ((ex_rs1_fwd1 + id_ex_imm1) & ~32'd1):
                     id_trap_fire ? machine_trap_vector                       :
                     id_branch_redirect0 ? id_branch_target0                 :
                     id_mret_fire ? machine_mepc                              :
                     id_sret_fire ? supervisor_mepc                           :
                     (id_sfence_fire || id_fence_i_fire) ? squash_replay_pc     :
                     id_amo_accept ? (if_id_pc0 + 32'd4) :
                     squash_replay_en ? squash_replay_pc                     :
                     if_pred_taken0  ? if_pred_target0                       :
                     pc_plus8;

    // =========================================================
    // EX/MEM — slot 0
    // =========================================================
    reg [31:0] ex_mem_alu0, ex_mem_rs2_0, ex_mem_wb0;
    reg [31:0] ex_mem_pc0;
    reg [4:0]  ex_mem_rd0;
    reg [2:0]  ex_mem_funct3_0;
    reg        ex_mem_mem_read0, ex_mem_mem_write0;
    reg        ex_mem_reg_write0, ex_mem_mem_to_reg0;
    reg        ex_mem_ecall0, ex_mem_halt0;
    reg        ex_mem_amo0;
    reg [4:0]  ex_mem_amo_op0;
    reg        ex_mem_valid0;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            ex_mem_alu0 <= 0; ex_mem_rs2_0 <= 0; ex_mem_wb0 <= 0; ex_mem_pc0 <= 0;
            ex_mem_rd0 <= 0; ex_mem_funct3_0 <= 0;
            ex_mem_mem_read0 <= 0; ex_mem_mem_write0 <= 0;
            ex_mem_reg_write0 <= 0; ex_mem_mem_to_reg0 <= 0;
            ex_mem_ecall0 <= 0; ex_mem_halt0 <= 0;
            ex_mem_amo0 <= 0; ex_mem_amo_op0 <= 0;
            ex_mem_valid0 <= 0;
        end else if (!ex_mem_halt0) begin
            ex_mem_pc0         <= id_ex_pc0;
            ex_mem_alu0        <= id_ex_amo0 ? ex_rs1_fwd0 : ex_alu_result0;
            ex_mem_rs2_0       <= ex_rs2_fwd0;
            ex_mem_wb0         <= ex_wb_val0;
            ex_mem_rd0         <= id_ex_rd0;
            ex_mem_funct3_0    <= id_ex_funct3_0;
            ex_mem_mem_read0   <= id_ex_amo0 ? 1'b1 : id_ex_mem_read0;
            ex_mem_mem_write0  <= id_ex_amo0 ? (id_ex_funct7_0[6:2] != 5'b00010) : id_ex_mem_write0;
            ex_mem_reg_write0  <= id_ex_reg_write0;
            ex_mem_mem_to_reg0 <= id_ex_mem_to_reg0;
            ex_mem_ecall0      <= id_ex_ecall0;
            ex_mem_halt0       <= id_ex_halt0;
            ex_mem_amo0        <= id_ex_amo0 && id_ex_valid0;
            ex_mem_amo_op0     <= id_ex_funct7_0[6:2];
            ex_mem_valid0      <= id_ex_valid0;
        end
    end

    assign ex_mem_fwd_val0 = ex_mem_mem_to_reg0 ? mem_read_data0 : ex_mem_wb0;

    // =========================================================
    // EX/MEM — slot 1
    // =========================================================
    reg [31:0] ex_mem_alu1, ex_mem_rs2_1, ex_mem_wb1;
    reg [31:0] ex_mem_pc1;
    reg [4:0]  ex_mem_rd1;
    reg [2:0]  ex_mem_funct3_1;
    reg        ex_mem_mem_read1, ex_mem_mem_write1;
    reg        ex_mem_reg_write1, ex_mem_mem_to_reg1;
    reg        ex_mem_ecall1, ex_mem_halt1;
    reg        ex_mem_valid1;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            ex_mem_alu1 <= 0; ex_mem_rs2_1 <= 0; ex_mem_wb1 <= 0; ex_mem_pc1 <= 0;
            ex_mem_rd1 <= 0; ex_mem_funct3_1 <= 0;
            ex_mem_mem_read1 <= 0; ex_mem_mem_write1 <= 0;
            ex_mem_reg_write1 <= 0; ex_mem_mem_to_reg1 <= 0;
            ex_mem_ecall1 <= 0; ex_mem_halt1 <= 0;
            ex_mem_valid1 <= 0;
        end else if (!ex_mem_halt1) begin
            ex_mem_pc1         <= id_ex_pc1;
            ex_mem_alu1        <= ex_alu_result1;
            ex_mem_rs2_1       <= ex_rs2_fwd1;
            ex_mem_wb1         <= ex_wb_val1;
            ex_mem_rd1         <= id_ex_rd1;
            ex_mem_funct3_1    <= id_ex_funct3_1;
            ex_mem_mem_read1   <= id_ex_mem_read1;
            ex_mem_mem_write1  <= id_ex_mem_write1;
            ex_mem_reg_write1  <= id_ex_reg_write1;
            ex_mem_mem_to_reg1 <= id_ex_mem_to_reg1;
            ex_mem_ecall1      <= id_ex_ecall1;
            ex_mem_halt1       <= id_ex_halt1;
            ex_mem_valid1      <= id_ex_valid1;
        end
    end

    assign ex_mem_fwd_val1 = ex_mem_mem_to_reg1 ? mem_read_data1 : ex_mem_wb1;

    // =========================================================
    // MEM
    // =========================================================
    // Valid bits are architectural side-effect qualifiers, not just hazard
    // metadata. Gate every external effect so flushed/bubble control fields
    // cannot issue phantom stores, loads, atomics, or register writes.
    assign mem_read0   = ex_mem_mem_read0 && ex_mem_valid0;
    assign mem_write0  = ex_mem_mem_write0 && ex_mem_valid0;
    assign mem_addr0   = ex_mem_alu0;
    assign mem_wdata0  = ex_mem_rs2_0;
    assign mem_funct30 = ex_mem_funct3_0;
    assign mem_amo0    = ex_mem_amo0 && ex_mem_valid0;
    assign mem_amo_op0 = ex_mem_amo_op0;
    assign mem_amo_lr0 = ex_mem_amo0 && (ex_mem_amo_op0 == 5'b00010);
    assign mem_amo_sc0 = ex_mem_amo0 && (ex_mem_amo_op0 == 5'b00011);

    assign mem_read1   = ex_mem_mem_read1 && ex_mem_valid1;
    assign mem_write1  = ex_mem_mem_write1 && ex_mem_valid1;
    assign mem_addr1   = ex_mem_alu1;
    assign mem_wdata1  = ex_mem_rs2_1;
    assign mem_funct31 = ex_mem_funct3_1;

    // =========================================================
    // MEM/WB — slot 0
    // =========================================================
    reg [31:0] mem_wb_wb0, mem_wb_mem0;
    reg [4:0]  mem_wb_rd0;
    reg        mem_wb_reg_write0, mem_wb_mem_to_reg0;
    reg        mem_wb_ecall0, mem_wb_halt0;
    reg        mem_wb_valid0;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mem_wb_wb0 <= 0; mem_wb_mem0 <= 0; mem_wb_rd0 <= 0;
            mem_wb_reg_write0 <= 0; mem_wb_mem_to_reg0 <= 0;
            mem_wb_ecall0 <= 0; mem_wb_halt0 <= 0;
            mem_wb_amo0 <= 0;
            mem_wb_valid0 <= 0;
        end else begin
            mem_wb_wb0         <= ex_mem_wb0;
            mem_wb_mem0        <= mem_read_data0;
            mem_wb_rd0         <= ex_mem_rd0;
            mem_wb_reg_write0  <= ex_mem_reg_write0;
            mem_wb_mem_to_reg0 <= ex_mem_mem_to_reg0;
            mem_wb_ecall0      <= ex_mem_ecall0;
            mem_wb_halt0       <= ex_mem_halt0;
            mem_wb_amo0        <= ex_mem_amo0;
            mem_wb_valid0      <= ex_mem_valid0;
        end
    end

    // =========================================================
    // MEM/WB — slot 1
    // =========================================================
    reg [31:0] mem_wb_wb1, mem_wb_mem1;
    reg [4:0]  mem_wb_rd1;
    reg        mem_wb_reg_write1, mem_wb_mem_to_reg1;
    reg        mem_wb_ecall1, mem_wb_halt1;
    reg        mem_wb_valid1;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mem_wb_wb1 <= 0; mem_wb_mem1 <= 0; mem_wb_rd1 <= 0;
            mem_wb_reg_write1 <= 0; mem_wb_mem_to_reg1 <= 0;
            mem_wb_ecall1 <= 0; mem_wb_halt1 <= 0;
            mem_wb_valid1 <= 0;
        end else begin
            mem_wb_wb1         <= ex_mem_wb1;
            mem_wb_mem1        <= mem_read_data1;
            mem_wb_rd1         <= ex_mem_rd1;
            mem_wb_reg_write1  <= ex_mem_reg_write1;
            mem_wb_mem_to_reg1 <= ex_mem_mem_to_reg1;
            mem_wb_ecall1      <= ex_mem_ecall1;
            mem_wb_halt1       <= ex_mem_halt1;
            mem_wb_valid1      <= ex_mem_valid1;
        end
    end

    assign older_pipeline_busy = id_ex_valid0 || id_ex_valid1 ||
                                 ex_mem_valid0 || ex_mem_valid1 ||
                                 mem_wb_valid0 || mem_wb_valid1;

    assign id_amo_accept = if_id_valid0 && id_amo0 && !id_illegal0 &&
                           !id_trap_candidate && !atomic_lock && !older_pipeline_busy &&
                           !older_redirect_pending && !csr_hazard_stall;
    assign id_amo_drain_stall = if_id_valid0 && id_amo0 && !id_illegal0 &&
                                !id_amo_accept;

    always @(posedge clk or posedge rst) begin
        if (rst)
            atomic_lock <= 1'b0;
        else if (id_amo_accept)
            atomic_lock <= 1'b1;
        else if (mem_wb_amo0 && mem_wb_valid0)
            atomic_lock <= 1'b0;
    end

    // Count ordinary retired instructions at WB. ECALL traps/halts are not
    // retired; serialized MRET and FENCE.I retire at their ID-stage fire point.
    assign retire_count = {1'b0, (mem_wb_valid0 && !mem_wb_ecall0)} +
                          {1'b0, (mem_wb_valid1 && !mem_wb_ecall1)} +
                          {1'b0, (id_mret_fire || id_sret_fire || id_sfence_fire || id_fence_i_fire)};

    // =========================================================
    // WB
    // =========================================================
    assign reg_wd0    = mem_wb_mem_to_reg0 ? mem_wb_mem0 : mem_wb_wb0;
    assign reg_wa0    = mem_wb_rd0;
    assign reg_write0 = mem_wb_reg_write0 && mem_wb_valid0;

    assign reg_wd1    = mem_wb_mem_to_reg1 ? mem_wb_mem1 : mem_wb_wb1;
    assign reg_wa1    = mem_wb_rd1;
    assign reg_write1 = mem_wb_reg_write1 && mem_wb_valid1;

    assign ecall = (mem_wb_ecall0 && mem_wb_valid0) || (mem_wb_ecall1 && mem_wb_valid1);
    assign halt  = (mem_wb_halt0  && mem_wb_valid0) || (mem_wb_halt1  && mem_wb_valid1);

    assign mem_wb_fwd_val0 = reg_wd0;
    assign mem_wb_fwd_val1 = reg_wd1;

    // =========================================================
    // Hazard unit
    // =========================================================
    hazard hz (
        .s0_id_ex_rd        (id_ex_rd0),
        .s0_id_ex_mem_read  (id_ex_mem_read0),
        .s1_id_ex_rd        (id_ex_rd1),
        .s1_id_ex_mem_read  (id_ex_mem_read1),
        .s0_if_id_rs1       (id_rs1_0),
        .s0_if_id_rs2       (id_rs2_0),
        .s0_if_id_use_rs1   (id_use_rs1_0),
        .s0_if_id_use_rs2   (id_use_rs2_0),
        .s1_if_id_rs1       (id_rs1_1),
        .s1_if_id_rs2       (id_rs2_1),
        .s1_if_id_use_rs1   (id_use_rs1_1),
        .s1_if_id_use_rs2   (id_use_rs2_1),
        .s0_ex_branch_taken (ex_take_branch0),
        .s0_ex_jal          (1'b0),
        .s0_ex_jalr         (1'b0),
        .s1_ex_branch_taken (ex_take_branch1),
        .s1_ex_jal          (id_ex_jal1),
        .s1_ex_jalr         (id_ex_jalr1),
        .s0_id_rd           (id_rd0),
        .s0_id_reg_write    (id_reg_write0),
        .s1_id_rs1          (id_rs1_1),
        .s1_id_rs2          (id_rs2_1),
        .s0_id_branch       (id_branch0),
        .s0_id_branch_taken (id_branch_taken0_id),
        .s0_id_branch_pred_taken(if_id_pred_taken0),
        .s0_id_jal          (id_jal0),
        .s0_id_jalr         (id_jalr0),
        .s0_id_mem_read     (id_mem_read0),
        .s0_s1_mem_dep      (s0_s1_mem_dep),
        .stall_if           (hz_stall_if),
        .stall_id           (hz_stall_id),
        .flush_id           (hz_flush_id),
        .flush_ex           (hz_flush_ex),
        .squash_s1          (hz_squash_s1)
    );

    assign stall_if = hz_stall_if || csr_hazard_stall || id_serial_drain_stall || id_s0_addr_wait ||
                      id_amo_drain_stall || atomic_lock;
    assign stall_id = hz_stall_id || csr_hazard_stall || id_serial_drain_stall || id_s0_addr_wait ||
                      id_amo_drain_stall || atomic_lock;
    // On trap entry, the faulting/current IF/ID instruction is squashed, but
    // older ID/EX work must still advance and retire. Flushing EX here loses
    // a prior instruction and corrupts architectural state (notably on IRQs).
    assign flush_ex = hz_flush_ex || csr_hazard_stall || id_serial_drain_stall || id_s0_addr_wait ||
                      id_amo_drain_stall || id_mret_fire || id_sret_fire || id_sfence_fire || id_fence_i_fire;
    assign squash_s1 = (hz_squash_s1 && !id_s0_addr_wait) || id_s0_serial ||
                       (id_s1_priv && !id_s0_addr_wait);
    assign flush_id = (hz_flush_id && !id_s0_addr_wait && !id_amo_drain_stall && !id_serial_drain_stall) || id_branch_redirect0 || id_trap_fire ||
                      id_amo_accept || id_mret_fire || id_sret_fire || id_sfence_fire || id_fence_i_fire ||
                      ((id_s0_serial || ((id_s1_priv && !id_pred_taken_ctrl0) && !id_s0_addr_wait)) &&
                       !hz_stall_id && !csr_hazard_stall && !id_serial_drain_stall &&
                       !id_amo_drain_stall);

    // =========================================================
    // Forwarding unit
    // =========================================================
    forward fwd_unit (
        .s0_id_ex_rs1       (id_ex_rs1_0),
        .s0_id_ex_rs2       (id_ex_rs2_0),
        .s1_id_ex_rs1       (id_ex_rs1_1),
        .s1_id_ex_rs2       (id_ex_rs2_1),
        .s0_ex_mem_rd       (ex_mem_rd0),
        .s0_ex_mem_reg_write(ex_mem_reg_write0),
        .s1_ex_mem_rd       (ex_mem_rd1),
        .s1_ex_mem_reg_write(ex_mem_reg_write1),
        .s0_mem_wb_rd       (mem_wb_rd0),
        .s0_mem_wb_reg_write(mem_wb_reg_write0),
        .s1_mem_wb_rd       (mem_wb_rd1),
        .s1_mem_wb_reg_write(mem_wb_reg_write1),
        .s0_ex_rd           (id_ex_rd0),
        .s0_ex_reg_write    (id_ex_reg_write0),
        .fwd_a0(fwd_a0), .fwd_b0(fwd_b0),
        .fwd_a1(fwd_a1), .fwd_b1(fwd_b1)
    );

    // Hybrid predictor update on resolved slot 0 conditional branches.
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            hybp_ghr <= {HYBP_GHR_BITS{1'b0}};
            ras_top_ptr <= {RAS_PTR_BITS{1'b0}};
            ras_count <= {(RAS_PTR_BITS+1){1'b0}};
            for (hybp_i = 0; hybp_i < HYBP_ENTRIES; hybp_i = hybp_i + 1) begin
                hybp_local_pht[hybp_i]  <= 2'b00;
                hybp_global_pht[hybp_i] <= 2'b00;
                hybp_choice_pht[hybp_i] <= 2'b01;
                btb_valid[hybp_i] <= 1'b0;
                btb_tag[hybp_i] <= 32'b0;
                btb_target[hybp_i] <= 32'b0;
            end
            for (ras_i = 0; ras_i < RAS_DEPTH; ras_i = ras_i + 1)
                ras_stack[ras_i] <= 32'b0;
        end else if (!pipe_halt && if_id_valid0 && !hz_stall_id) begin
            if (id_branch0) begin
                case (hybp_local_pht[if_id_local_idx0])
                    2'b00: hybp_local_pht[if_id_local_idx0] <= id_branch_taken0_id ? 2'b01 : 2'b00;
                    2'b01: hybp_local_pht[if_id_local_idx0] <= id_branch_taken0_id ? 2'b10 : 2'b00;
                    2'b10: hybp_local_pht[if_id_local_idx0] <= id_branch_taken0_id ? 2'b11 : 2'b01;
                    2'b11: hybp_local_pht[if_id_local_idx0] <= id_branch_taken0_id ? 2'b11 : 2'b10;
                    default: hybp_local_pht[if_id_local_idx0] <= 2'b00;
                endcase

                case (hybp_global_pht[if_id_global_idx0])
                    2'b00: hybp_global_pht[if_id_global_idx0] <= id_branch_taken0_id ? 2'b01 : 2'b00;
                    2'b01: hybp_global_pht[if_id_global_idx0] <= id_branch_taken0_id ? 2'b10 : 2'b00;
                    2'b10: hybp_global_pht[if_id_global_idx0] <= id_branch_taken0_id ? 2'b11 : 2'b01;
                    2'b11: hybp_global_pht[if_id_global_idx0] <= id_branch_taken0_id ? 2'b11 : 2'b10;
                    default: hybp_global_pht[if_id_global_idx0] <= 2'b00;
                endcase

                if (if_id_global_pred_taken0 != if_id_local_pred_taken0) begin
                    if (if_id_global_pred_taken0 == id_branch_taken0_id) begin
                        case (hybp_choice_pht[if_id_global_idx0])
                            2'b00: hybp_choice_pht[if_id_global_idx0] <= 2'b01;
                            2'b01: hybp_choice_pht[if_id_global_idx0] <= 2'b10;
                            2'b10: hybp_choice_pht[if_id_global_idx0] <= 2'b11;
                            2'b11: hybp_choice_pht[if_id_global_idx0] <= 2'b11;
                            default: hybp_choice_pht[if_id_global_idx0] <= 2'b01;
                        endcase
                    end else begin
                        case (hybp_choice_pht[if_id_global_idx0])
                            2'b00: hybp_choice_pht[if_id_global_idx0] <= 2'b00;
                            2'b01: hybp_choice_pht[if_id_global_idx0] <= 2'b00;
                            2'b10: hybp_choice_pht[if_id_global_idx0] <= 2'b01;
                            2'b11: hybp_choice_pht[if_id_global_idx0] <= 2'b10;
                            default: hybp_choice_pht[if_id_global_idx0] <= 2'b01;
                        endcase
                    end
                end

                hybp_ghr <= {hybp_ghr[HYBP_GHR_BITS-2:0], id_branch_taken0_id};

                if (id_branch_taken0_id) begin
                    btb_valid[if_id_pc0[9:2]] <= 1'b1;
                    btb_tag[if_id_pc0[9:2]] <= if_id_pc0;
                    btb_target[if_id_pc0[9:2]] <= if_id_pc0 + id_imm0;
                end
            end else if (id_jal0) begin
                btb_valid[if_id_pc0[9:2]] <= 1'b1;
                btb_tag[if_id_pc0[9:2]] <= if_id_pc0;
                btb_target[if_id_pc0[9:2]] <= id_jal_target0;
            end else if (id_jalr0) begin
                btb_valid[if_id_pc0[9:2]] <= 1'b1;
                btb_tag[if_id_pc0[9:2]] <= if_id_pc0;
                btb_target[if_id_pc0[9:2]] <= id_jalr_target0;
            end

            if (id_is_ret0 && (ras_count != 0)) begin
                if (ras_count == 1) begin
                    ras_count <= 0;
                end else begin
                    ras_count <= ras_count - 1'b1;
                    ras_top_ptr <= ras_top_ptr - 1'b1;
                end
            end

            if (id_is_call0 && (ras_count < RAS_DEPTH_COUNT)) begin
                if (ras_count == 0) begin
                    ras_top_ptr <= {RAS_PTR_BITS{1'b0}};
                    ras_stack[0] <= if_id_pc0 + 32'd4;
                end else begin
                    ras_top_ptr <= ras_top_ptr + 1'b1;
                    ras_stack[ras_top_ptr + 1'b1] <= if_id_pc0 + 32'd4;
                end
                ras_count <= ras_count + 1'b1;
            end
        end
    end

endmodule
