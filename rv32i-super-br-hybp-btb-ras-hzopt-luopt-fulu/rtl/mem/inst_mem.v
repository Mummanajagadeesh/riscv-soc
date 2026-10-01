`include "defines.v"

module inst_mem #(
    parameter HEX_FILE = "hex/inst_mem.hex",
    parameter BASE_ADDR = 32'h00000000,
    parameter WRITE_ENABLE = 1'b1,
    parameter MEM_WORDS = `INST_MEM_WORDS
) (
    input         clk,
    input  [`ADDR_WIDTH-1:0] addr,
    output [`INST_WIDTH-1:0] instruction,
    input         we0,
    input  [31:0]  waddr0,
    input  [31:0]  wdata0,
    input  [2:0]   wfunct30,
    input         we1,
    input  [31:0]  waddr1,
    input  [31:0]  wdata1,
    input  [2:0]   wfunct31
);
    reg [`INST_WIDTH-1:0] mem [0:MEM_WORDS-1];
    integer init_word;

    initial begin
        for (init_word = 0; init_word < MEM_WORDS; init_word = init_word + 1)
            mem[init_word] = 32'h0000_0013;
        $readmemh(HEX_FILE, mem);
    end

    // Low no-MMU userspace addresses are legal on the simulated platform.
    // Translate those directly, and translate physical RAM addresses relative
    // to BASE_ADDR. Do not modulo-wrap fetches beyond this instruction window.
    wire [31:0] offset_addr = (BASE_ADDR[31] && !addr[31]) ? addr : (addr - BASE_ADDR);
    wire [31:0] fetch_word_index = offset_addr >> 2;
    wire [$clog2(MEM_WORDS)-1:0] idx = fetch_word_index[$clog2(MEM_WORDS)-1:0];
    assign instruction = (fetch_word_index < MEM_WORDS) ? mem[idx] : 32'h0000_0013;

    // Keep fetched instructions coherent with stores to the same byte-addressed
    // physical region. FENCE.I in core_top drains older writes and refetches.
    task write_bytes;
        input [31:0] store_addr;
        input [31:0] store_data;
        input [2:0]  store_funct3;
        integer count;
        integer i;
        integer word_index;
        integer byte_index;
        reg [31:0] byte_offset;
        begin
            case (store_funct3)
                3'b000: count = 1;
                3'b001: count = 2;
                3'b010: count = 4;
                default: count = 0;
            endcase
            byte_offset = (BASE_ADDR[31] && !store_addr[31]) ? store_addr : (store_addr - BASE_ADDR);
            for (i = 0; i < count; i = i + 1) begin
                word_index = (byte_offset + i) >> 2;
                byte_index = (byte_offset + i) & 3;
                if ((word_index >= 0) && (word_index < MEM_WORDS))
                    mem[word_index][byte_index*8 +: 8] <= store_data[i*8 +: 8];
            end
        end
    endtask

    always @(posedge clk) begin
        if (WRITE_ENABLE && we0)
            write_bytes(waddr0, wdata0, wfunct30);
        if (WRITE_ENABLE && we1)
            write_bytes(waddr1, wdata1, wfunct31);
    end
endmodule
