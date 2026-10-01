`include "defines.v"

module control (
    input      [6:0] opcode,
    input      [2:0] funct3,
    input      [6:0] funct7,
    input      [11:0] system_imm,
    input      [4:0]  rd,
    output reg       mem_read,
    output reg       mem_write,
    output reg       reg_write,
    output reg       mem_to_reg,
    output reg       alu_src,
    output reg [1:0] alu_op,
    output reg       auipc,
    output reg       is_lui,
    output reg [2:0] imm_type,
    output reg       branch,
    output reg       jal,
    output reg       jalr,
    output reg       ecall,
    output reg       ebreak,
    output reg       mret,
    output reg       sret,
    output reg       sfence_vma,
    output reg       wfi,
    output reg       fence_i,
    output reg       halt,
    output reg       csr_read,
    output reg       csr_write,
    output reg       illegal
);
    always @(*) begin
        mem_read    = 1'b0;
        mem_write   = 1'b0;
        reg_write   = 1'b0;
        mem_to_reg  = 1'b0;
        alu_src     = 1'b0;
        alu_op      = 2'b00;
        auipc       = 1'b0;
        is_lui      = 1'b0;
        imm_type    = 3'b000;
        branch      = 1'b0;
        jal         = 1'b0;
        jalr        = 1'b0;
        ecall       = 1'b0;
        ebreak      = 1'b0;
        mret        = 1'b0;
        sret        = 1'b0;
        sfence_vma  = 1'b0;
        wfi         = 1'b0;
        fence_i     = 1'b0;
        halt        = 1'b0;
        csr_read    = 1'b0;
        csr_write   = 1'b0;
        illegal     = 1'b0;

        case (opcode)
            `OPCODE_LOAD: begin
                case (funct3)
                    3'b000, 3'b001, 3'b010, 3'b100, 3'b101: begin
                        mem_read   = 1'b1;
                        reg_write  = 1'b1;
                        mem_to_reg = 1'b1;
                        alu_src    = 1'b1;
                        alu_op     = 2'b00;
                        imm_type   = 3'b000;
                    end
                    default: illegal = 1'b1;
                endcase
            end
            `OPCODE_STORE: begin
                case (funct3)
                    3'b000, 3'b001, 3'b010: begin
                        mem_write = 1'b1;
                        alu_src   = 1'b1;
                        alu_op    = 2'b00;
                        imm_type  = 3'b001;
                    end
                    default: illegal = 1'b1;
                endcase
            end
            `OPCODE_BRANCH: begin
                case (funct3)
                    3'b000, 3'b001, 3'b100, 3'b101, 3'b110, 3'b111: begin
                        branch   = 1'b1;
                        alu_op   = 2'b01;
                        imm_type = 3'b010;
                    end
                    default: illegal = 1'b1;
                endcase
            end
            `OPCODE_JALR: begin
                if (funct3 == 3'b000) begin
                    reg_write = 1'b1;
                    jalr      = 1'b1;
                    alu_op    = 2'b00;
                    imm_type  = 3'b000;
                end else illegal = 1'b1;
            end
            `OPCODE_JAL: begin
                reg_write = 1'b1;
                jal       = 1'b1;
                alu_op    = 2'b00;
                imm_type  = 3'b100;
            end
            `OPCODE_AUIPC: begin
                reg_write = 1'b1;
                auipc     = 1'b1;
                alu_src   = 1'b1;
                alu_op    = 2'b11;
                imm_type  = 3'b011;
            end
            `OPCODE_LUI: begin
                reg_write = 1'b1;
                is_lui    = 1'b1;
                alu_src   = 1'b1;
                alu_op    = 2'b11;
                imm_type  = 3'b011;
            end
            `OPCODE_OP_IMM: begin
                case (funct3)
                    3'b001: begin
                        if (funct7 == 7'b0000000) begin
                            reg_write = 1'b1; alu_src = 1'b1; alu_op = 2'b10; imm_type = 3'b000;
                        end else illegal = 1'b1;
                    end
                    3'b101: begin
                        if ((funct7 == 7'b0000000) || (funct7 == 7'b0100000)) begin
                            reg_write = 1'b1; alu_src = 1'b1; alu_op = 2'b10; imm_type = 3'b000;
                        end else illegal = 1'b1;
                    end
                    3'b000, 3'b010, 3'b011, 3'b100, 3'b110, 3'b111: begin
                        reg_write = 1'b1; alu_src = 1'b1; alu_op = 2'b10; imm_type = 3'b000;
                    end
                    default: illegal = 1'b1;
                endcase
            end
            `OPCODE_AMO: begin
                if ((funct3 == 3'b010) &&
                    ((funct7[6:2] == 5'b00010) || (funct7[6:2] == 5'b00011) ||
                     (funct7[6:2] == 5'b00001) || (funct7[6:2] == 5'b00000) ||
                     (funct7[6:2] == 5'b00100) || (funct7[6:2] == 5'b01000) ||
                     (funct7[6:2] == 5'b01100) || (funct7[6:2] == 5'b10000) ||
                     (funct7[6:2] == 5'b10100) || (funct7[6:2] == 5'b11000) ||
                     (funct7[6:2] == 5'b11100))) begin
                    mem_read   = 1'b1;
                    mem_write  = 1'b1;
                    reg_write  = 1'b1;
                    mem_to_reg = 1'b1;
                end else illegal = 1'b1;
            end
            `OPCODE_OP: begin
                if ((funct7 == 7'b0000000) ||
                    (funct7 == 7'b0000001) ||
                    ((funct7 == 7'b0100000) && ((funct3 == 3'b000) || (funct3 == 3'b101)))) begin
                    reg_write = 1'b1;
                    alu_op    = 2'b10;
                end else illegal = 1'b1;
            end
            `OPCODE_FENCE: begin
                if (funct3 == 3'b001)
                    fence_i = 1'b1;
                else if (funct3 != 3'b000)
                    illegal = 1'b1;
                // FENCE is a no-op in the current strongly ordered memory.
            end
            `OPCODE_CSR: begin
                if (funct3 == 3'b000) begin
                    case (system_imm)
                        12'h000: begin ecall = 1'b1; halt = 1'b1; end
                        12'h001: ebreak = 1'b1;
                        12'h302: mret = 1'b1;
                        12'h102: sret = 1'b1;
                        12'h105: wfi = 1'b1;
                        default: begin
                            if ((system_imm[11:5] == 7'b0001001) && (rd == 5'b0))
                                sfence_vma = 1'b1;
                            else
                                illegal = 1'b1;
                        end
                    endcase
                end else if ((funct3 == 3'b001) || (funct3 == 3'b010) ||
                             (funct3 == 3'b011) || (funct3 == 3'b101) ||
                             (funct3 == 3'b110) || (funct3 == 3'b111)) begin
                    reg_write = 1'b1;
                    csr_read  = 1'b1;
                    csr_write = 1'b1;
                end else illegal = 1'b1;
            end
            default: illegal = 1'b1;
        endcase
    end
endmodule
