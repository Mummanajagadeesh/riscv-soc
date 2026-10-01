`include "defines.v"

// Shared architectural machine CSR bank and M-mode trap/counter state.
// Only the currently implemented architectural bits are writable; reserved and
// unsupported bits are WARL-masked to zero.
//
// CSR instructions have one serialized update port. Trap entry and MRET use
// higher priority than ordinary machine CSR writes. The cycle/time counters are
// simulation-clock ticks; platform timer interrupts are implemented separately.
module csr_reg (
    input         clk,
    input         rst,
    input         timer_irq,
    input         we,
    input  [11:0] addr,
    input  [31:0] wdata,
    input  [2:0]  funct3,
    input  [1:0]  retire_count,
    input         trap_enter,
    input  [31:0] trap_pc,
    input  [31:0] trap_cause,
    input  [31:0] trap_value,
    input         trap_return,
    input         trap_return_s,
    output [31:0] rdata,
    output [31:0] trap_vector,
    output [31:0] mepc_value,
    output [31:0] sepc_value,
    output [1:0]  privilege_mode,
    output [31:0] mstatus_value,
    output [31:0] sstatus_value,
    output [31:0] mie_value,
    output [31:0] mip_value,
    output [31:0] mideleg_value
);

    reg [31:0] mstatus;
    reg [31:0] mie;
    reg [31:0] mtvec;
    reg [31:0] mscratch;
    reg [31:0] mepc;
    reg [31:0] mcause;
    reg [31:0] mtval;
    reg [31:0] mip;
    reg [31:0] medeleg, mideleg;
    reg [31:0] stvec, sscratch, sepc, scause, stval, satp;
    reg [31:0] pmpcfg0, pmpaddr0;
    reg [1:0]  privilege;
    reg [63:0] mcycle;
    reg [63:0] minstret;

    function [31:0] read_csr;
        input [11:0] csr_addr;
        begin
            case (csr_addr)
                `CSR_SSTATUS:   read_csr = mstatus & 32'h0000_0122;
                `CSR_SIE:       read_csr = mie & mideleg;
                `CSR_STVEC:     read_csr = stvec;
                `CSR_SSCRATCH:  read_csr = sscratch;
                `CSR_SEPC:      read_csr = sepc;
                `CSR_SCAUSE:    read_csr = scause;
                `CSR_STVAL:     read_csr = stval;
                `CSR_SIP:       read_csr = (mip & mideleg) | ((timer_irq && mideleg[7]) ? 32'h0000_0020 : 32'b0);
                `CSR_SATP:      read_csr = satp;
                `CSR_MEDELEG:   read_csr = medeleg;
                `CSR_MIDELEG:   read_csr = mideleg;
                `CSR_PMPCFG0:   read_csr = pmpcfg0;
                `CSR_PMPADDR0:  read_csr = pmpaddr0;
                `CSR_MSTATUS:   read_csr = mstatus;
                `CSR_MIE:        read_csr = mie;
                `CSR_MTVEC:      read_csr = mtvec;
                `CSR_MSCRATCH:   read_csr = mscratch;
                `CSR_MEPC:       read_csr = mepc;
                `CSR_MCAUSE:     read_csr = mcause;
                `CSR_MTVAL:      read_csr = mtval;
                `CSR_MIP:        read_csr = mip | (timer_irq ? 32'h0000_0080 : 32'b0);
                `CSR_MCYCLE:     read_csr = mcycle[31:0];
                `CSR_MCYCLEH:    read_csr = mcycle[63:32];
                `CSR_MINSTRET:   read_csr = minstret[31:0];
                `CSR_MINSTRETH:  read_csr = minstret[63:32];
                `CSR_CYCLE:      read_csr = mcycle[31:0];
                `CSR_CYCLEH:     read_csr = mcycle[63:32];
                // Until a platform timer is attached, TIME uses the same
                // monotonically increasing simulation tick as CYCLE.
                `CSR_TIME:       read_csr = mcycle[31:0];
                `CSR_TIMEH:      read_csr = mcycle[63:32];
                `CSR_INSTRET:    read_csr = minstret[31:0];
                `CSR_INSTRETH:   read_csr = minstret[63:32];
                `CSR_MISA:       read_csr = 32'h4004_1101; // RV32, A, I, M, S
                `CSR_MVENDORID:  read_csr = 32'b0;
                `CSR_MARCHID:    read_csr = 32'b0;
                `CSR_MIMPID:     read_csr = 32'b0;
                `CSR_MHARTID:    read_csr = 32'b0; // one hart
                default:         read_csr = 32'b0;
            endcase
        end
    endfunction

    function [31:0] csr_write_value;
        input [31:0] old_value;
        input [31:0] source_value;
        input [2:0]  operation;
        begin
            case (operation[1:0])
                2'b01: csr_write_value = source_value;              // CSRRW[I]
                2'b10: csr_write_value = old_value | source_value;  // CSRRS[I]
                2'b11: csr_write_value = old_value & ~source_value; // CSRRC[I]
                default: csr_write_value = old_value;
            endcase
        end
    endfunction

    wire [31:0] old_value = read_csr(addr);
    wire [31:0] new_value = csr_write_value(old_value, wdata, funct3);

    wire trap_is_interrupt = trap_cause[31];
    wire [4:0] trap_code = trap_cause[4:0];
    wire trap_delegated = (privilege != 2'b11) &&
                          (trap_is_interrupt ? mideleg[trap_code] : medeleg[trap_code]);
    wire [31:0] mtvec_base = {mtvec[31:2], 2'b00};
    wire [31:0] stvec_base = {stvec[31:2], 2'b00};
    wire [31:0] mtvec_offset = (trap_is_interrupt && (mtvec[1:0] == 2'b01)) ? {25'b0, trap_code, 2'b00} : 32'b0;
    wire [31:0] stvec_offset = (trap_is_interrupt && (stvec[1:0] == 2'b01)) ? {25'b0, trap_code, 2'b00} : 32'b0;

    assign rdata = old_value;
    assign trap_vector = trap_delegated ? (stvec_base + stvec_offset) : (mtvec_base + mtvec_offset);
    assign mepc_value = {mepc[31:2], 2'b00};
    assign sepc_value = {sepc[31:2], 2'b00};
    assign privilege_mode = privilege;
    assign mstatus_value = mstatus;
    assign sstatus_value = mstatus & 32'h0000_0122;
    assign mie_value = mie;
    assign mip_value = mip | (timer_irq ? 32'h0000_0080 : 32'b0);
    assign mideleg_value = mideleg;

    // 64-bit machine counters. Writes to the machine aliases take effect
    // instead of the automatic increment on that edge; user aliases are RO.
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mcycle  <= 64'b0;
            minstret <= 64'b0;
        end else begin
            if (we && (addr == `CSR_MCYCLE)) begin
                mcycle <= {mcycle[63:32], new_value};
            end else if (we && (addr == `CSR_MCYCLEH)) begin
                mcycle <= {new_value, mcycle[31:0]};
            end else begin
                mcycle <= mcycle + 64'd1;
            end

            if (we && (addr == `CSR_MINSTRET)) begin
                minstret <= {minstret[63:32], new_value};
            end else if (we && (addr == `CSR_MINSTRETH)) begin
                minstret <= {new_value, minstret[31:0]};
            end else begin
                minstret <= minstret + {{62{1'b0}}, retire_count};
            end
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mstatus  <= 32'b0;
            mie      <= 32'b0;
            mtvec    <= 32'b0;
            mscratch <= 32'b0;
            mepc     <= 32'b0;
            mcause   <= 32'b0;
            mtval    <= 32'b0;
            mip      <= 32'b0;
            medeleg  <= 32'b0;
            mideleg  <= 32'b0;
            stvec    <= 32'b0;
            sscratch <= 32'b0;
            sepc     <= 32'b0;
            scause   <= 32'b0;
            stval    <= 32'b0;
            satp     <= 32'b0;
            pmpcfg0  <= 32'b0;
            pmpaddr0 <= 32'b0;
            privilege <= 2'b11; // reset in M-mode
        end else if (trap_enter && trap_delegated) begin
            sepc   <= {trap_pc[31:2], 2'b00};
            scause <= trap_cause;
            stval  <= trap_value;
            mstatus[5] <= mstatus[1];
            mstatus[1] <= 1'b0;
            mstatus[8] <= (privilege == 2'b01);
            privilege  <= 2'b01;
        end else if (trap_enter) begin
            mepc   <= {trap_pc[31:2], 2'b00};
            mcause <= trap_cause;
            mtval  <= trap_value;
            mstatus[7]     <= mstatus[3];
            mstatus[3]     <= 1'b0;
            mstatus[12:11] <= privilege;
            privilege      <= 2'b11;
        end else if (trap_return_s) begin
            privilege  <= mstatus[8] ? 2'b01 : 2'b00;
            mstatus[1] <= mstatus[5];
            mstatus[5] <= 1'b1;
            mstatus[8] <= 1'b0;
        end else if (trap_return) begin
            privilege      <= mstatus[12:11];
            mstatus[3]     <= mstatus[7];
            mstatus[7]     <= 1'b1;
            mstatus[12:11] <= 2'b00;
        end else if (we) begin
            case (addr)
                `CSR_SSTATUS:  mstatus <= (mstatus & ~32'h0000_0122) | (new_value & 32'h0000_0122);
                `CSR_SIE:      mie <= (mie & ~mideleg) | (new_value & mideleg & 32'h0000_0222);
                `CSR_SIP:      mip <= (mip & ~mideleg) | (new_value & mideleg & 32'h0000_0222);
                `CSR_MSTATUS:  mstatus <= {19'b0,
                                                (new_value[12:11] == 2'b10) ? 2'b00 : new_value[12:11],
                                                2'b0, new_value[8], new_value[7], 1'b0,
                                                new_value[5], 1'b0, new_value[3], 1'b0,
                                                new_value[1], 1'b0};
                `CSR_MIE:      mie <= new_value & 32'h0000_0aaa;
                `CSR_MIP:      mip <= (mip & ~32'h0000_000a) | (new_value & 32'h0000_000a);
                `CSR_MEDELEG:  medeleg <= new_value & 32'h0000_ffff;
                `CSR_MIDELEG:  mideleg <= new_value & 32'h0000_0222;
                // Single-entry, M-mode PMP CSRs are retained as WARL-visible
                // state. The current physical RAM model does not enforce PMP.
                `CSR_PMPCFG0:  pmpcfg0 <= {24'b0, (new_value[7:0] & 8'h9f)};
                `CSR_PMPADDR0: pmpaddr0 <= new_value;
                `CSR_STVEC:    stvec <= {new_value[31:2], (new_value[1:0] == 2'b01) ? 2'b01 : 2'b00};
                `CSR_SSCRATCH: sscratch <= new_value;
                `CSR_SEPC:     sepc <= {new_value[31:2], 2'b00};
                `CSR_SCAUSE:   scause <= new_value;
                `CSR_STVAL:    stval <= new_value;
                `CSR_SATP:     satp <= new_value;
                `CSR_MTVEC:    mtvec <= {new_value[31:2], (new_value[1:0] == 2'b01) ? 2'b01 : 2'b00};
                `CSR_MSCRATCH: mscratch <= new_value;
                `CSR_MEPC:     mepc     <= {new_value[31:2], 2'b00};
                `CSR_MCAUSE:   mcause   <= new_value;
                `CSR_MTVAL:    mtval    <= new_value;
                // MISA is fixed by this implementation; identity CSRs and
                // user counter aliases are read-only. Decoder rejects writes
                // to architecturally RO addresses and unsupported CSR numbers.
                default: begin end
            endcase
        end
    end
endmodule
