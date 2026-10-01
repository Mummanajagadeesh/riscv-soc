`include "defines.v"

module hazard (
    input  [4:0]  s0_id_ex_rd,
    input         s0_id_ex_mem_read,
    input  [4:0]  s1_id_ex_rd,
    input         s1_id_ex_mem_read,
    input  [4:0]  s0_if_id_rs1,
    input  [4:0]  s0_if_id_rs2,
    input         s0_if_id_use_rs1,
    input         s0_if_id_use_rs2,
    input  [4:0]  s1_if_id_rs1,
    input  [4:0]  s1_if_id_rs2,
    input         s1_if_id_use_rs1,
    input         s1_if_id_use_rs2,
    input         s0_ex_branch_taken,
    input         s0_ex_jal,
    input         s0_ex_jalr,
    input         s1_ex_branch_taken,
    input         s1_ex_jal,
    input         s1_ex_jalr,
    input  [4:0]  s0_id_rd,
    input         s0_id_reg_write,
    input  [4:0]  s1_id_rs1,
    input  [4:0]  s1_id_rs2,
    // slot 0 ID-stage control — needed to squash slot 1 when s0 is branch/jal/jalr
    input         s0_id_branch,
    input         s0_id_branch_taken,
    input         s0_id_branch_pred_taken,
    input         s0_id_jal,
    input         s0_id_jalr,
    // slot 0/1 ID-stage memory operations — needed for inter-slot squash checks
    input         s0_id_mem_read,
    input         s0_s1_mem_dep,
    output        stall_if,
    output        stall_id,
    output        flush_id,
    output        flush_ex,
    output        squash_s1
);
    // hzopt: only stall for operands that must be consumed in ID stage.
    // In this core that is slot-0 branch/jalr (early control resolution).
    wire s0_need_id_rs1 = s0_id_branch || s0_id_jalr;
    wire s0_need_id_rs2 = s0_id_branch;

    // Load-use stall: slot in ID/EX is a load whose rd is needed by slot-0 IF/ID
    // for an ID-stage consumer. Other ops can use MEM->EX forwarding.
    wire s0_load_use = s0_id_ex_mem_read && s0_id_ex_rd != 0 &&
                       ((s0_if_id_use_rs1 && s0_need_id_rs1 && (s0_id_ex_rd == s0_if_id_rs1)) ||
                        (s0_if_id_use_rs2 && s0_need_id_rs2 && (s0_id_ex_rd == s0_if_id_rs2)));
    wire s1_load_use = s1_id_ex_mem_read && s1_id_ex_rd != 0 &&
                       ((s0_if_id_use_rs1 && s0_need_id_rs1 && (s1_id_ex_rd == s0_if_id_rs1)) ||
                        (s0_if_id_use_rs2 && s0_need_id_rs2 && (s1_id_ex_rd == s0_if_id_rs2)));
    wire load_use_stall = s0_load_use || s1_load_use;

    // Branch/jump flush
    wire do_flush = s0_ex_branch_taken || s0_ex_jal || s0_ex_jalr ||
                    s1_ex_branch_taken || s1_ex_jal || s1_ex_jalr;

    // If EX stage is redirecting control flow this cycle, give flush priority
    // over load-use stalls so PC can take the redirect target.
    wire eff_load_use_stall = load_use_stall && !do_flush;

    // Inter-slot RAW squash:
    // Case 1: slot 0 in ID is a load and slot 1 in ID reads the same rd.
    // Slot 1 must be replayed (single-issue fallback) because slot 0 load result
    // is not available until MEM stage.
    wire inter_slot_load_raw = s0_id_mem_read && s0_id_rd != 0 &&
                               ((s1_if_id_use_rs1 && (s0_id_rd == s1_id_rs1)) ||
                                (s1_if_id_use_rs2 && (s0_id_rd == s1_id_rs2)));

    // Case 2: slot 0 in ID redirects control flow — slot 1 at PC+4 is wrong-path.
    // flush_ex will kill the ID/EX registers next cycle, but slot 1 must not enter
    // the pipeline this cycle either. Note: we check the ID-stage decode of slot 0,
    // not the EX-stage (which is one cycle later).
    wire inter_slot_ctrl = (s0_id_branch && (s0_id_branch_taken || s0_id_branch_pred_taken)) ||
                           s0_id_jal || s0_id_jalr;

    // Case 3: Inter-slot memory dependency (from core_top alias check).
    wire inter_slot_mem = s0_s1_mem_dep;

    assign stall_if  = eff_load_use_stall;
    assign stall_id  = eff_load_use_stall;
    // squash_s1 requests slot-1 replay at PC=s0_pc+4. IF/ID captures using the
    // current fetch group in the same edge, so we must flush IF/ID on squash to
    // avoid latching an out-of-order pair. If a load-use stall is active, hold
    // IF/ID instead of flushing so slot 0 is not dropped.
    assign flush_id  = do_flush || ((inter_slot_load_raw ||
                        (inter_slot_ctrl && !s0_id_branch_pred_taken) ||
                        inter_slot_mem) && !eff_load_use_stall);
    // On load-use, stall IF/ID and inject bubble into EX (same as single-issue core).
    assign flush_ex  = do_flush || load_use_stall;
    assign squash_s1 = inter_slot_load_raw || inter_slot_ctrl || inter_slot_mem;
endmodule
