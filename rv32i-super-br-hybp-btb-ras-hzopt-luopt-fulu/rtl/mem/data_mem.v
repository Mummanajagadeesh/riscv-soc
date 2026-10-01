`include "defines.v"

module data_mem #(
    parameter HEX_FILE  = "hex/data_mem.hex",
    parameter INST_HEX  = "hex/inst_mem.hex",
    parameter BASE_ADDR = 32'h00000000,
    parameter MEM_WORDS = `DATA_MEM_WORDS,
    parameter UNIFIED_MEMORY = 1'b0
) (
    input                         clk,

    // port 0 (older)
    input                         we0,
    input                         re0,
    input  [`ADDR_WIDTH-1:0]      addr0,
    input  [`DATA_WIDTH-1:0]      write_data0,
    input  [2:0]                  funct3_0,
    input                         amo0,
    input  [4:0]                  amo_op0,
    input                         amo_lr0,
    input                         amo_sc0,
    output reg [`DATA_WIDTH-1:0]  read_data0,

    // port 1 (younger)
    input                         we1,
    input                         re1,
    input  [`ADDR_WIDTH-1:0]      addr1,
    input  [`DATA_WIDTH-1:0]      write_data1,
    input  [2:0]                  funct3_1,
    output reg [`DATA_WIDTH-1:0]  read_data1,

    // Optional combinational instruction fetch ports for single-array mode.
    input  [31:0]                 inst_addr0,
    output [31:0]                 instruction0,
    input  [31:0]                 inst_addr1,
    output [31:0]                 instruction1
);

    reg [`DATA_WIDTH-1:0] mem [0:MEM_WORDS-1];
    integer init_word;

    initial begin
        for (init_word = 0; init_word < MEM_WORDS; init_word = init_word + 1)
            mem[init_word] = 32'b0;
        // Sparse images write only allocated words; loading the instruction
        // image second merges code with data/DTB/initrd in the same RAM array.
        $readmemh(HEX_FILE, mem);
        if (UNIFIED_MEMORY)
            $readmemh(INST_HEX, mem);
    end

    wire [31:0] inst_offset0 = (BASE_ADDR[31] && !inst_addr0[31]) ? inst_addr0 : (inst_addr0 - BASE_ADDR);
    wire [31:0] inst_offset1 = (BASE_ADDR[31] && !inst_addr1[31]) ? inst_addr1 : (inst_addr1 - BASE_ADDR);
    wire [31:0] inst_index0 = inst_offset0 >> 2;
    wire [31:0] inst_index1 = inst_offset1 >> 2;
    assign instruction0 = (UNIFIED_MEMORY && inst_index0 < MEM_WORDS) ? mem[inst_index0] : 32'h0000_0013;
    assign instruction1 = (UNIFIED_MEMORY && inst_index1 < MEM_WORDS) ? mem[inst_index1] : 32'h0000_0013;

    wire [31:0] offset0 = addr0 - BASE_ADDR;
    wire [31:0] offset1 = addr1 - BASE_ADDR;
    reg reservation_valid;
    reg [31:0] reservation_addr;
    wire [31:0] amo_old = mem[(offset0 >> 2) % MEM_WORDS];
    wire amo_sc_success = reservation_valid && (reservation_addr == offset0);
    wire [31:0] amo_new;

    function [31:0] atomic_value;
        input [4:0] op;
        input [31:0] old_value;
        input [31:0] operand;
        begin
            case (op)
                5'b00000: atomic_value = old_value + operand; // AMOADD.W
                5'b00001: atomic_value = operand;             // AMOSWAP.W
                5'b00100: atomic_value = old_value ^ operand; // AMOXOR.W
                5'b01000: atomic_value = old_value | operand; // AMOOR.W
                5'b01100: atomic_value = old_value & operand; // AMOAND.W
                5'b10000: atomic_value = ($signed(old_value) < $signed(operand)) ? old_value : operand;
                5'b10100: atomic_value = ($signed(old_value) > $signed(operand)) ? old_value : operand;
                5'b11000: atomic_value = (old_value < operand) ? old_value : operand;
                5'b11100: atomic_value = (old_value > operand) ? old_value : operand;
                default:  atomic_value = old_value;
            endcase
        end
    endfunction

    assign amo_new = atomic_value(amo_op0, amo_old, write_data0);

    // Little-endian byte access used by the load/store functions. The modulo
    // matches this simple RAM's existing power-of-two address wrap behavior.
    function [7:0] read_byte;
        input [31:0] byte_offset;
        integer word_index;
        integer byte_index;
        begin
            word_index = (byte_offset >> 2) % MEM_WORDS;
            byte_index = {30'b0, byte_offset[1:0]};
            read_byte = mem[word_index][byte_index*8 +: 8];
        end
    endfunction

    // Port 1 is the younger lane. If port 0 stores bytes in the same pair,
    // bypass those older bytes into the younger load rather than returning
    // the pre-write RAM value from the combinational read port.
    function [7:0] read_byte_s1;
        input [31:0] byte_offset;
        integer store_count;
        integer i;
        integer target_word;
        integer target_byte;
        integer store_word;
        integer store_byte;
        reg [7:0] result_byte;
        begin
            result_byte = read_byte(byte_offset);
            target_word = (byte_offset >> 2) % MEM_WORDS;
            target_byte = {30'b0, byte_offset[1:0]};
            case (funct3_0)
                3'b000: store_count = 1;
                3'b001: store_count = 2;
                3'b010: store_count = 4;
                default: store_count = 0;
            endcase
            if (we0) begin
                for (i = 0; i < store_count; i = i + 1) begin
                    store_word = ((offset0 + i) >> 2) % MEM_WORDS;
                    store_byte = (offset0 + i) & 3;
                    if ((target_word == store_word) && (target_byte == store_byte))
                        result_byte = write_data0[i*8 +: 8];
                end
            end
            read_byte_s1 = result_byte;
        end
    endfunction

    function [31:0] load_value;
        input [31:0] byte_offset;
        input [2:0]  load_funct3;
        reg [7:0] b0, b1, b2, b3;
        begin
            b0 = read_byte(byte_offset);
            b1 = read_byte(byte_offset + 32'd1);
            b2 = read_byte(byte_offset + 32'd2);
            b3 = read_byte(byte_offset + 32'd3);
            case (load_funct3)
                3'b000: load_value = {{24{b0[7]}}, b0};
                3'b001: load_value = {{16{b1[7]}}, b1, b0};
                3'b010: load_value = {b3, b2, b1, b0};
                3'b100: load_value = {24'b0, b0};
                3'b101: load_value = {16'b0, b1, b0};
                default: load_value = {b3, b2, b1, b0};
            endcase
        end
    endfunction

    function [31:0] load_value_s1;
        input [31:0] byte_offset;
        input [2:0]  load_funct3;
        reg [7:0] b0, b1, b2, b3;
        begin
            b0 = read_byte_s1(byte_offset);
            b1 = read_byte_s1(byte_offset + 32'd1);
            b2 = read_byte_s1(byte_offset + 32'd2);
            b3 = read_byte_s1(byte_offset + 32'd3);
            case (load_funct3)
                3'b000: load_value_s1 = {{24{b0[7]}}, b0};
                3'b001: load_value_s1 = {{16{b1[7]}}, b1, b0};
                3'b010: load_value_s1 = {b3, b2, b1, b0};
                3'b100: load_value_s1 = {24'b0, b0};
                3'b101: load_value_s1 = {16'b0, b1, b0};
                default: load_value_s1 = {b3, b2, b1, b0};
            endcase
        end
    endfunction

    // Store low 1/2/4 bytes at the byte address, including word-boundary
    // crossings. Called for slot 0 before slot 1 so younger writes win.
    task write_bytes;
        input [31:0] byte_offset;
        input [31:0] value;
        input [2:0]  store_funct3;
        integer count;
        integer i;
        integer word_index;
        integer byte_index;
        begin
            case (store_funct3)
                3'b000: count = 1;
                3'b001: count = 2;
                3'b010: count = 4;
                default: count = 0;
            endcase
            for (i = 0; i < count; i = i + 1) begin
                word_index = ((byte_offset + i) >> 2) % MEM_WORDS;
                byte_index = (byte_offset + i) & 3;
                mem[word_index][byte_index*8 +: 8] <= value[i*8 +: 8];
            end
        end
    endtask

    initial begin
        reservation_valid = 1'b0;
        reservation_addr = 32'b0;
    end

    always @(posedge clk) begin
        // A-Extension operations are serialized by core_top into slot 0.
        if (amo0 && amo_lr0) begin
            reservation_valid <= 1'b1;
            reservation_addr <= offset0;
        end else if (amo0 && amo_sc0) begin
            if (amo_sc_success)
                mem[(offset0 >> 2) % MEM_WORDS] <= write_data0;
            reservation_valid <= 1'b0;
        end else if (amo0 && we0) begin
            mem[(offset0 >> 2) % MEM_WORDS] <= amo_new;
            reservation_valid <= 1'b0;
        end else begin
            // Port 0 is architecturally older; port 1's nonblocking assignments
            // later in this block win if both lanes target the same byte.
            if (we0)
                write_bytes(offset0, write_data0, funct3_0);
            if (we1)
                write_bytes(offset1, write_data1, funct3_1);
            if (we0 || we1)
                reservation_valid <= 1'b0;
        end
    end

    always @(*) begin
        read_data0 = re0 ? (amo0 ? (amo_sc0 ? {31'b0, !amo_sc_success} : amo_old)
                                  : load_value(offset0, funct3_0)) : `ZERO_WORD;
        read_data1 = re1 ? load_value_s1(offset1, funct3_1) : `ZERO_WORD;
    end
endmodule
