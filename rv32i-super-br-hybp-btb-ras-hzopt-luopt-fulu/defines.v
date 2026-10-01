`ifndef RV32I_DEFINES_V
`define RV32I_DEFINES_V

`define DATA_WIDTH     32
`define ADDR_WIDTH     32
`define REG_ADDR_WIDTH 5
`define INST_WIDTH     32
`define ZERO_WORD      32'h00000000
`define ZERO_REG       5'b00000

`define OPCODE_LUI     7'b0110111
`define OPCODE_AUIPC   7'b0010111
`define OPCODE_JAL     7'b1101111
`define OPCODE_JALR    7'b1100111
`define OPCODE_BRANCH  7'b1100011
`define OPCODE_LOAD    7'b0000011
`define OPCODE_STORE   7'b0100011
`define OPCODE_AMO     7'b0101111
`define OPCODE_OP_IMM  7'b0010011
`define OPCODE_OP      7'b0110011
`define OPCODE_FENCE   7'b0001111
`define OPCODE_ECALL   7'b1110011
`define OPCODE_CSR     7'b1110011

`define ALU_ADD    5'b00000
`define ALU_SUB    5'b00001
`define ALU_AND    5'b00010
`define ALU_OR     5'b00011
`define ALU_XOR    5'b00100
`define ALU_SLL    5'b00101
`define ALU_SRL    5'b00110
`define ALU_SRA    5'b00111
`define ALU_SLT    5'b01000
`define ALU_SLTU   5'b01001
`define ALU_LUI    5'b01010
`define ALU_AUIPC  5'b01011
`define ALU_MUL    5'b01100
`define ALU_MULH   5'b01101
`define ALU_MULHSU 5'b01110
`define ALU_MULHU  5'b01111
`define ALU_DIV   5'b10000
`define ALU_DIVU  5'b10001
`define ALU_REM   5'b10010
`define ALU_REMU  5'b10011
`define ALU_NOP   5'b11111

`define INST_MEM_WORDS 4096
`define DATA_MEM_WORDS 2048

`define PC_WIDTH 32

`define CSR_SSTATUS  12'h100
`define CSR_SIE      12'h104
`define CSR_STVEC    12'h105
`define CSR_SSCRATCH 12'h140
`define CSR_SEPC     12'h141
`define CSR_SCAUSE   12'h142
`define CSR_STVAL    12'h143
`define CSR_SIP      12'h144
`define CSR_SATP     12'h180
`define CSR_MEDELEG  12'h302
`define CSR_MIDELEG  12'h303
`define CSR_MSTATUS  12'h300
`define CSR_MISA     12'h301
`define CSR_MIE      12'h304
`define CSR_MTVEC    12'h305
`define CSR_MSCRATCH 12'h340
`define CSR_MEPC     12'h341
`define CSR_MCAUSE   12'h342
`define CSR_MTVAL    12'h343
`define CSR_MIP      12'h344
`define CSR_PMPCFG0  12'h3A0
`define CSR_PMPADDR0 12'h3B0
`define CSR_MCYCLE   12'hB00
`define CSR_MINSTRET 12'hB02
`define CSR_MCYCLEH  12'hB80
`define CSR_MINSTRETH 12'hB82
`define CSR_CYCLE    12'hC00
`define CSR_TIME     12'hC01
`define CSR_INSTRET  12'hC02
`define CSR_CYCLEH   12'hC80
`define CSR_TIMEH    12'hC81
`define CSR_INSTRETH 12'hC82
`define CSR_MVENDORID 12'hF11
`define CSR_MARCHID  12'hF12
`define CSR_MIMPID   12'hF13
`define CSR_MHARTID  12'hF14

`endif
