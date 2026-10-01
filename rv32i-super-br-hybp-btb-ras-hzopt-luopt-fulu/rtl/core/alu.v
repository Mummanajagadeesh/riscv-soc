`include "defines.v"

module alu (
    input  [`DATA_WIDTH-1:0] a,
    input  [`DATA_WIDTH-1:0] b,
    input  [4:0]             alu_op,
    output reg [`DATA_WIDTH-1:0] result,
    output                      zero
);
    wire signed [63:0] a_signed_64 = {{32{a[31]}}, a};
    wire signed [63:0] b_signed_64 = {{32{b[31]}}, b};
    wire        [63:0] a_unsigned_64 = {32'b0, a};
    wire        [63:0] b_unsigned_64 = {32'b0, b};
    wire signed [63:0] product_ss = a_signed_64 * b_signed_64;
    wire        [63:0] product_su = a_signed_64 * b_unsigned_64;
    wire        [63:0] product_uu = a_unsigned_64 * b_unsigned_64;

    assign zero = (result == `ZERO_WORD);

    always @(*) begin
        case (alu_op)
            `ALU_ADD:    result = a + b;
            `ALU_SUB:    result = a - b;
            `ALU_SLL:    result = a << b[4:0];
            `ALU_SLT:    result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            `ALU_SLTU:   result = (a < b) ? 32'd1 : 32'd0;
            `ALU_XOR:    result = a ^ b;
            `ALU_SRL:    result = a >> b[4:0];
            `ALU_SRA:    result = $signed(a) >>> b[4:0];
            `ALU_OR:     result = a | b;
            `ALU_AND:    result = a & b;
            `ALU_LUI:    result = b;
            `ALU_AUIPC:  result = a + b;

            `ALU_MUL:    result = a * b;
            `ALU_MULH:   result = product_ss[63:32];
            `ALU_MULHSU: result = product_su[63:32];
            `ALU_MULHU:  result = product_uu[63:32];

            // Avoid a conditional operator here: Verilog can propagate the
            // unsigned type of its other arm into the signed division operand.
            `ALU_DIV: begin
                if (b == 32'b0)
                    result = 32'hffff_ffff;
                else if ((a == 32'h8000_0000) && (b == 32'hffff_ffff))
                    result = 32'h8000_0000;
                else
                    result = $signed(a) / $signed(b);
            end
            `ALU_DIVU: begin
                if (b == 32'b0)
                    result = 32'hffff_ffff;
                else
                    result = a / b;
            end
            `ALU_REM: begin
                if (b == 32'b0)
                    result = a;
                else if ((a == 32'h8000_0000) && (b == 32'hffff_ffff))
                    result = 32'b0;
                else
                    result = $signed(a) % $signed(b);
            end
            `ALU_REMU: begin
                if (b == 32'b0)
                    result = a;
                else
                    result = a % b;
            end

            `ALU_NOP:    result = `ZERO_WORD;
            default:     result = `ZERO_WORD;
        endcase
    end
endmodule
