`include "defines.v"

module tb_supervisor_trap;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/supervisor_trap_inst.hex"),
        .DATA_HEX("build/supervisor_trap_data.hex"),
        .ECALL_HALT(1'b0)
    ) uut (
        .clk(clk), .rst(rst), .pc_debug(pc_debug), .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug), .mem_read_debug(mem_read_debug),
        .halted(halted)
    );

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    always @(posedge clk) begin
        if (rst)
            cycles <= 0;
        else
            cycles <= cycles + 1;
    end

    initial begin
        rst = 1'b1;
        cycles = 0;
        #20 rst = 1'b0;
        while ((uut.core.regs.rf[21] !== 32'h0000_0055) && (cycles < 1200))
            @(posedge clk);
        #10;

        if (uut.core.regs.rf[21] !== 32'h0000_0055)
            $fatal(1, "M/S privilege transition test timed out: pc=%08x mode=%0d mcause=%08x scause=%08x",
                   pc_debug, uut.core.csr_file.privilege, uut.core.csr_file.mcause, uut.core.csr_file.scause);
        if (uut.core.regs.rf[8] !== 32'd8 || uut.core.regs.rf[9] !== uut.core.regs.rf[22])
            $fatal(1, "U ECALL was not delegated to S: scause=%08x sepc=%08x expected=%08x",
                   uut.core.regs.rf[8], uut.core.regs.rf[9], uut.core.regs.rf[22]);
        if (uut.core.regs.rf[18] !== 32'd9 || uut.core.regs.rf[20] !== 32'h44 ||
            uut.core.regs.rf[19] !== 32'h0000_0020)
            $fatal(1, "S-to-M ECALL/MRET path failed: mcause=%08x s4=%08x s5=%08x",
                   uut.core.regs.rf[18], uut.core.regs.rf[20], uut.core.regs.rf[19]);
        if (uut.core.regs.rf[25] !== 32'b0 || uut.core.regs.rf[24] !== 32'h0000_0018)
            $fatal(1, "unexpected U continuation or missing U-mode effect: fail=%08x s8=%08x",
                   uut.core.regs.rf[25], uut.core.regs.rf[24]);
        if (uut.core.csr_file.privilege !== 2'b01 || uut.core.csr_file.scause !== 32'd8 ||
            uut.core.csr_file.mcause !== 32'd9)
            $fatal(1, "final privilege/trap CSRs incorrect: mode=%0d scause=%08x mcause=%08x",
                   uut.core.csr_file.privilege, uut.core.csr_file.scause, uut.core.csr_file.mcause);

        $display("PASS: M->U->S delegated trap, SRET, S->M SBI ECALL, MRET (%0d cycles)", cycles);
        $finish;
    end
endmodule
