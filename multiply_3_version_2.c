/* multiply@./multiply.rb:1 */

#undef OPT_CHECKED_RUN
#define OPT_CHECKED_RUN 0

VALUE
_mjit2(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp)
{
    VALUE stack[2];
    static const rb_iseq_t *original_iseq = 0x7ff8d98203f0;
    static const VALUE *const original_body_iseq = (VALUE *)0x7ff8d9077190;

label_0: /* getlocal_WC_0 */
{
    MAYBE_UNUSED(unsigned int) stack_size = 0;
    MAYBE_UNUSED(VALUE) val;
    MAYBE_UNUSED(lindex_t) idx;
    MAYBE_UNUSED(rb_num_t) level;
    level = 0;
    idx = (lindex_t)0x5;
    {
        val = *(vm_get_ep(GET_EP(), level) - idx);
        RB_DEBUG_COUNTER_INC(lvar_get);
        (void)RB_DEBUG_COUNTER_INC_IF(lvar_get_dynamic, level > 0);
    }
    stack[0] = val;
}

label_2: /* getlocal_WC_0 */
{
    MAYBE_UNUSED(unsigned int) stack_size = 1;
    MAYBE_UNUSED(VALUE) val;
    MAYBE_UNUSED(lindex_t) idx;
    MAYBE_UNUSED(rb_num_t) level;
    level = 0;
    idx = (lindex_t)0x4;
    {
        val = *(vm_get_ep(GET_EP(), level) - idx);
        RB_DEBUG_COUNTER_INC(lvar_get);
        (void)RB_DEBUG_COUNTER_INC_IF(lvar_get_dynamic, level > 0);
    }
    stack[1] = val;
}

label_4: /* opt_mult */
{
    MAYBE_UNUSED(unsigned int) stack_size = 2;
    MAYBE_UNUSED(CALL_CACHE) cc;
    MAYBE_UNUSED(CALL_INFO) ci;
    MAYBE_UNUSED(VALUE) obj, recv, val;
    ci = (CALL_INFO)0x7ff8d905b150;
    cc = (CALL_CACHE)0x7ff8d9077200;
    recv = stack[0];
    obj = stack[1];
    {
        val = vm_opt_mult(recv, obj);

        if (val == Qundef) {
            reg_cfp->sp = vm_base_ptr(reg_cfp) + 2;
            reg_cfp->pc = original_body_iseq + 4;
            RB_DEBUG_COUNTER_INC(mjit_cancel_opt_insn);
            goto cancel;
        }
    }
    stack[0] = val;
}

label_7: /* getlocal_WC_0 */
{
    MAYBE_UNUSED(unsigned int) stack_size = 1;
    MAYBE_UNUSED(VALUE) val;
    MAYBE_UNUSED(lindex_t) idx;
    MAYBE_UNUSED(rb_num_t) level;
    level = 0;
    idx = (lindex_t)0x3;
    {
        val = *(vm_get_ep(GET_EP(), level) - idx);
        RB_DEBUG_COUNTER_INC(lvar_get);
        (void)RB_DEBUG_COUNTER_INC_IF(lvar_get_dynamic, level > 0);
    }
    stack[1] = val;
}

label_9: /* opt_mult */
{
    MAYBE_UNUSED(unsigned int) stack_size = 2;
    MAYBE_UNUSED(CALL_CACHE) cc;
    MAYBE_UNUSED(CALL_INFO) ci;
    MAYBE_UNUSED(VALUE) obj, recv, val;
    ci = (CALL_INFO)0x7ff8d905b160;
    cc = (CALL_CACHE)0x7ff8d9077228;
    recv = stack[0];
    obj = stack[1];
    {
        val = vm_opt_mult(recv, obj);

        if (val == Qundef) {
            reg_cfp->sp = vm_base_ptr(reg_cfp) + 2;
            reg_cfp->pc = original_body_iseq + 9;
            RB_DEBUG_COUNTER_INC(mjit_cancel_opt_insn);
            goto cancel;
        }
    }
    stack[0] = val;
}

label_12: /* leave */
{
    MAYBE_UNUSED(unsigned int) stack_size = 1;
    MAYBE_UNUSED(VALUE) val;
    val = stack[0];
    reg_cfp->pc = original_body_iseq + 13;
    reg_cfp->sp = vm_base_ptr(reg_cfp) + 0;
    {
        if (OPT_CHECKED_RUN) {
            const VALUE *const bp = vm_base_ptr(GET_CFP());
            if (GET_SP() != bp) {
                vm_stack_consistency_error(ec, GET_CFP(), bp);
            }
        }

        RUBY_VM_CHECK_INTS(ec);

        if (vm_pop_frame(ec, GET_CFP(), GET_EP())) {
#if OPT_CALL_THREADED_CODE
            rb_ec_thread_ptr(ec)->retval = val;
            return 0;
#else
            return val;
#endif
        }
        else {
#if OPT_CALL_THREADED_CODE
            rb_ec_thread_ptr(ec)->retval = val;
            return 0;
#else
            return val;
#endif
        }
    }
    stack[0] = val;
    if (UNLIKELY(!mjit_call_p)) {
        reg_cfp->sp = vm_base_ptr(reg_cfp) + 1;
        RB_DEBUG_COUNTER_INC(mjit_cancel_invalidate_all);
        goto cancel;
    }
}

send_cancel:
    RB_DEBUG_COUNTER_INC(mjit_cancel_send_inline);
    rb_mjit_iseq_compile_info(original_iseq->body)->disable_send_cache = true;
    rb_mjit_recompile_iseq(original_iseq);
    goto cancel;

ivar_cancel:
    RB_DEBUG_COUNTER_INC(mjit_cancel_ivar_inline);
    rb_mjit_iseq_compile_info(original_iseq->body)->disable_ivar_cache = true;
    rb_mjit_recompile_iseq(original_iseq);
    goto cancel;

cancel:
    RB_DEBUG_COUNTER_INC(mjit_cancel);
    *(vm_base_ptr(reg_cfp) + 0) = stack[0];
    *(vm_base_ptr(reg_cfp) + 1) = stack[1];
    return Qundef;

} // end of _mjit2
