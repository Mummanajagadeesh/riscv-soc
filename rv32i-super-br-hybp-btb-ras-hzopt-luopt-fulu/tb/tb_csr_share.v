`include "defines.v"

module tb_csr_share;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/csr_share_inst.hex"),
        .DATA_HEX("build/csr_share_data.hex")
    ) uut (
        .clk(clk),
        .rst(rst),
        .pc_debug(pc_debug),
        .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug),
        .mem_read_debug(mem_read_debug),
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
        while (!halted && cycles < 500)
            @(posedge clk);
        #10;

        if (!halted)
            $fatal(1, "CSR sharing test timed out at PC=%08x", pc_debug);
        if (uut.core.regs.rf[6] !== 32'h0000_005a)
            $fatal(1, "CSR write in slot 1 was not visible to slot 0: x6=%08x", uut.core.regs.rf[6]);
        if (uut.core.regs.rf[7] !== 32'b0)
            $fatal(1, "unimplemented CSR address aliased mtvec: x7=%08x", uut.core.regs.rf[7]);
        if (uut.core.regs.rf[29] !== 32'h0000_005a)
            $fatal(1, "CSRRWI did not return the old CSR value: x29=%08x", uut.core.regs.rf[29]);
        if (uut.core.regs.rf[30] !== 32'h0000_0007)
            $fatal(1, "CSRRWI zimm source is wrong: x30=%08x", uut.core.regs.rf[30]);
        if (uut.core.regs.rf[31] !== 32'h0000_000e)
            $fatal(1, "CSRRSI/CSRRCI update is wrong: x31=%08x", uut.core.regs.rf[31]);
        if (uut.core.regs.rf[28] !== 32'h0000_002a)
            $fatal(1, "slot-1 instruction was lost instead of replayed: x28=%08x", uut.core.regs.rf[28]);
        if (uut.core.regs.rf[18] == 0 || uut.core.regs.rf[19] < uut.core.regs.rf[18])
            $fatal(1, "cycle/time counters are not monotonic: cycle=%08x time=%08x",
                   uut.core.regs.rf[18], uut.core.regs.rf[19]);
        if (uut.core.regs.rf[20] == 0 || uut.core.regs.rf[21] < uut.core.regs.rf[18])
            $fatal(1, "instret/mcycle aliases are not readable: instret=%08x mcycle=%08x",
                   uut.core.regs.rf[20], uut.core.regs.rf[21]);
        if (uut.core.regs.rf[22] < uut.core.regs.rf[20])
            $fatal(1, "minstret alias did not advance: instret=%08x minstret=%08x",
                   uut.core.regs.rf[20], uut.core.regs.rf[22]);
        if (uut.core.regs.rf[23] !== 0 || uut.core.regs.rf[24] !== 0)
            $fatal(1, "counter high halves unexpectedly nonzero: cycleh=%08x instreth=%08x",
                   uut.core.regs.rf[23], uut.core.regs.rf[24]);

        $display("PASS: shared CSR state, slot replay, and cycle/time/instret counters (%0d cycles)", cycles);
        $finish;
    end
endmodule
