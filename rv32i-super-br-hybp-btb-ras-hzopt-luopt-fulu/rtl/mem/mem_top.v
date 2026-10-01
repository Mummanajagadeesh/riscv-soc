`include "defines.v"

module mem_top #(
    parameter INST_HEX  = "hex/inst_mem.hex",
    parameter DATA_HEX  = "hex/data_mem.hex",
    parameter BASE_ADDR = 32'h00000000,
    parameter COHERENT_CODE_WRITES = 1'b1,
    parameter INST_WORD_COUNT = `INST_MEM_WORDS,
    parameter DATA_WORD_COUNT = `DATA_MEM_WORDS,
    parameter UNIFIED_MEMORY = 1'b0
) (
    input         clk,
    input  [31:0] inst_addr,
    output [31:0] inst_data,
    input  [31:0] inst_addr1,
    output [31:0] inst_data1,
    input         mem_we0,
    input         mem_re0,
    input  [31:0] mem_addr0,
    input  [31:0] mem_wdata0,
    input  [2:0]  mem_funct3_0,
    input         mem_amo0,
    input  [4:0]  mem_amo_op0,
    input         mem_amo_lr0,
    input         mem_amo_sc0,
    output [31:0] mem_rdata0,
    input         mem_we1,
    input         mem_re1,
    input  [31:0] mem_addr1,
    input  [31:0] mem_wdata1,
    input  [2:0]  mem_funct3_1,
    output [31:0] mem_rdata1,
    output        timer_irq
);
    wire uart_sel0 = (mem_addr0 >= 32'h1000_0000) && (mem_addr0 < 32'h1000_0020);
    wire uart_sel1 = (mem_addr1 >= 32'h1000_0000) && (mem_addr1 < 32'h1000_0020);
    wire clint_sel0 = (mem_addr0 >= 32'h0200_0000) && (mem_addr0 < 32'h0201_0000);
    wire clint_sel1 = (mem_addr1 >= 32'h0200_0000) && (mem_addr1 < 32'h0201_0000);
    reg [63:0] clint_mtime;
    reg [63:0] clint_mtimecmp;
    wire [31:0] clint_data0 = (mem_addr0[2] ? clint_mtimecmp[63:32] : clint_mtimecmp[31:0]);
    wire [31:0] clint_data1 = (mem_addr1[2] ? clint_mtimecmp[63:32] : clint_mtimecmp[31:0]);
    wire addr0_mtime = (mem_addr0[15:3] == 13'h17ff);
    wire addr1_mtime = (mem_addr1[15:3] == 13'h17ff);
    wire [31:0] clint_read0 = addr0_mtime ? (mem_addr0[2] ? clint_mtime[63:32] : clint_mtime[31:0]) : clint_data0;
    wire [31:0] clint_read1 = addr1_mtime ? (mem_addr1[2] ? clint_mtime[63:32] : clint_mtime[31:0]) : clint_data1;
    wire dmem_we0 = mem_we0 && !uart_sel0 && !clint_sel0;
    wire dmem_re0 = mem_re0 && !uart_sel0 && !clint_sel0;
    wire dmem_we1 = mem_we1 && !uart_sel1 && !clint_sel1;
    wire dmem_re1 = mem_re1 && !uart_sel1 && !clint_sel1;
    wire [2:0] uart_idx0 = mem_addr0[2:0];
    wire [2:0] uart_idx1 = mem_addr1[2:0];
    reg [7:0] uart_lcr, uart_ier, uart_dll, uart_dlm, uart_scr;
    wire [31:0] dmem_rdata0, dmem_rdata1;
    reg [7:0] uart_data0, uart_data1;

    initial begin
        uart_lcr = 0; uart_ier = 0; uart_dll = 0; uart_dlm = 0; uart_scr = 0;
        clint_mtime = 0;
        clint_mtimecmp = 64'hffff_ffff_ffff_ffff;
    end

    always @(*) begin
        case (uart_idx0)
            3'd0: uart_data0 = uart_lcr[7] ? uart_dll : 8'b0;
            3'd1: uart_data0 = uart_lcr[7] ? uart_dlm : uart_ier;
            3'd2: uart_data0 = 8'h01;
            3'd3: uart_data0 = uart_lcr;
            3'd5: uart_data0 = 8'h60;
            3'd7: uart_data0 = uart_scr;
            default: uart_data0 = 0;
        endcase
        case (uart_idx1)
            3'd0: uart_data1 = uart_lcr[7] ? uart_dll : 8'b0;
            3'd1: uart_data1 = uart_lcr[7] ? uart_dlm : uart_ier;
            3'd2: uart_data1 = 8'h01;
            3'd3: uart_data1 = uart_lcr;
            3'd5: uart_data1 = 8'h60;
            3'd7: uart_data1 = uart_scr;
            default: uart_data1 = 0;
        endcase
    end

    assign timer_irq = (clint_mtime >= clint_mtimecmp);

    always @(posedge clk) begin
        clint_mtime <= clint_mtime + 64'd1;
        if (mem_we0 && clint_sel0 && (mem_addr0[15:3] == 13'h0800)) begin
            if (mem_addr0[2]) clint_mtimecmp[63:32] <= mem_wdata0;
            else clint_mtimecmp[31:0] <= mem_wdata0;
        end
        if (mem_we1 && clint_sel1 && (mem_addr1[15:3] == 13'h0800)) begin
            if (mem_addr1[2]) clint_mtimecmp[63:32] <= mem_wdata1;
            else clint_mtimecmp[31:0] <= mem_wdata1;
        end
    end

    always @(posedge clk) begin
        if (mem_we0 && uart_sel0) begin
            case (uart_idx0)
                3'd0: if (uart_lcr[7]) uart_dll <= mem_wdata0[7:0]; else $write("%c", mem_wdata0[7:0]);
                3'd1: if (uart_lcr[7]) uart_dlm <= mem_wdata0[7:0]; else uart_ier <= mem_wdata0[7:0];
                3'd3: uart_lcr <= mem_wdata0[7:0];
                3'd7: uart_scr <= mem_wdata0[7:0];
                default: begin end
            endcase
        end
        if (mem_we1 && uart_sel1) begin
            case (uart_idx1)
                3'd0: if (uart_lcr[7]) uart_dll <= mem_wdata1[7:0]; else $write("%c", mem_wdata1[7:0]);
                3'd1: if (uart_lcr[7]) uart_dlm <= mem_wdata1[7:0]; else uart_ier <= mem_wdata1[7:0];
                3'd3: uart_lcr <= mem_wdata1[7:0];
                3'd7: uart_scr <= mem_wdata1[7:0];
                default: begin end
            endcase
        end
    end

    wire [31:0] dmem_inst0, dmem_inst1;
    generate
        if (UNIFIED_MEMORY) begin : gen_unified_fetch
            assign inst_data = dmem_inst0;
            assign inst_data1 = dmem_inst1;
        end else begin : gen_split_fetch
            inst_mem #(
                .HEX_FILE(INST_HEX), .BASE_ADDR(BASE_ADDR),
                .WRITE_ENABLE(COHERENT_CODE_WRITES), .MEM_WORDS(INST_WORD_COUNT)
            ) imem (
                .clk(clk), .addr(inst_addr), .instruction(inst_data),
                .we0(dmem_we0 && !mem_amo0), .waddr0(mem_addr0), .wdata0(mem_wdata0), .wfunct30(mem_funct3_0),
                .we1(dmem_we1), .waddr1(mem_addr1), .wdata1(mem_wdata1), .wfunct31(mem_funct3_1)
            );
            assign inst_data1 = 32'h0000_0013;
        end
    endgenerate

    data_mem #(
        .HEX_FILE(DATA_HEX), .INST_HEX(INST_HEX), .BASE_ADDR(BASE_ADDR),
        .MEM_WORDS(DATA_WORD_COUNT), .UNIFIED_MEMORY(UNIFIED_MEMORY)
    ) dmem (
        .clk(clk), .we0(dmem_we0), .re0(dmem_re0), .addr0(mem_addr0),
        .write_data0(mem_wdata0), .funct3_0(mem_funct3_0),
        .amo0(mem_amo0 && !uart_sel0), .amo_op0(mem_amo_op0),
        .amo_lr0(mem_amo_lr0), .amo_sc0(mem_amo_sc0), .read_data0(dmem_rdata0),
        .we1(dmem_we1), .re1(dmem_re1), .addr1(mem_addr1),
        .write_data1(mem_wdata1), .funct3_1(mem_funct3_1), .read_data1(dmem_rdata1),
        .inst_addr0(inst_addr), .instruction0(dmem_inst0),
        .inst_addr1(inst_addr1), .instruction1(dmem_inst1)
    );

    assign mem_rdata0 = (uart_sel0 && mem_re0) ? {24'b0, uart_data0} :
                        (clint_sel0 && mem_re0) ? clint_read0 : dmem_rdata0;
    assign mem_rdata1 = (uart_sel1 && mem_re1) ? {24'b0, uart_data1} :
                        (clint_sel1 && mem_re1) ? clint_read1 : dmem_rdata1;
endmodule
