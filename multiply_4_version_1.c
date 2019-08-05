/* block in <main>@./multiply.rb:5 */

#undef OPT_CHECKED_RUN
#define OPT_CHECKED_RUN 0

VALUE
_mjit1(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp)
{
    VALUE stack[5];
    static const rb_iseq_t *original_iseq = 0x7fcf47904d90;
    static const VALUE *const original_body_iseq = (VALUE *)0x7fcf4777c620;

label_0: /* nop */
{
    MAYBE_UNUSED(unsigned int) stack_size = 0;
    {
        /* none */
    }
}

label_1: /* putself */
{
    MAYBE_UNUSED(unsigned int) stack_size = 0;
    MAYBE_UNUSED(VALUE) val;
    {
        val = GET_SELF();
    }
    stack[0] = val;
}

label_2: /* putobject */
{
    MAYBE_UNUSED(unsigned int) stack_size = 1;
    MAYBE_UNUSED(VALUE) val;
    val = (VALUE)0xe0000000000002;
    {
        /* */
    }
    stack[1] = val;
}

label_4: /* putobject */
{
    MAYBE_UNUSED(unsigned int) stack_size = 2;
    MAYBE_UNUSED(VALUE) val;
    val = (VALUE)0x120000000000002;
    {
        /* */
    }
    stack[2] = val;
}

label_6: /* putobject */
{
    MAYBE_UNUSED(unsigned int) stack_size = 3;
    MAYBE_UNUSED(VALUE) val;
    val = (VALUE)0x170000000000002;
    {
        /* */
    }
    stack[3] = val;
}

label_8: /* putobject */
{
    MAYBE_UNUSED(unsigned int) stack_size = 4;
    MAYBE_UNUSED(VALUE) val;
    val = (VALUE)0x1c8000000000002;
    {
        /* */
    }
    stack[4] = val;
}

label_10: /* opt_send_without_block */
{
    MAYBE_UNUSED(unsigned int) stack_size = 5;
    if (UNLIKELY(GET_GLOBAL_METHOD_STATE() != 143 ||
        RCLASS_SERIAL(CLASS_OF(stack[0])) != 4392)) {
        reg_cfp->pc = original_body_iseq + 10;
        reg_cfp->sp = vm_base_ptr(reg_cfp) + 5;
        goto send_cancel;
    }
    reg_cfp->pc = original_body_iseq + 13;
    reg_cfp->sp = vm_base_ptr(reg_cfp) + 5;
    *(reg_cfp->sp + -5) = stack[0];
    *(reg_cfp->sp + -4) = stack[1];
    *(reg_cfp->sp + -3) = stack[2];
    *(reg_cfp->sp + -2) = stack[3];
    *(reg_cfp->sp + -1) = stack[4];
    {
        struct rb_calling_info calling;
        calling.block_handler = VM_BLOCK_HANDLER_NONE;
        calling.argc = 4;
        calling.recv = stack[0];
        {
            VALUE v;
            vm_call_iseq_setup_normal(ec, reg_cfp, &calling, (const rb_callable_method_entry_t *)0x7fcf47904b10, 0, 4, 4);
            if ((v = mjit_exec(ec)) == Qundef) {
                VM_ENV_FLAGS_SET(ec->cfp->ep, VM_FRAME_FLAG_FINISH);
                v = vm_exec(ec, FALSE);
            }
            stack[0] = v;
        }
    }
    if (UNLIKELY(!mjit_call_p)) {
        reg_cfp->sp = vm_base_ptr(reg_cfp) + 1;
        RB_DEBUG_COUNTER_INC(mjit_cancel_invalidate_all);
        goto cancel;
    }
}

label_13: /* nop */
{
    MAYBE_UNUSED(unsigned int) stack_size = 1;
    {
        /* none */
    }
}

label_14: /* leave */
{
    MAYBE_UNUSED(unsigned int) stack_size = 1;
    MAYBE_UNUSED(VALUE) val;
    val = stack[0];
    reg_cfp->pc = original_body_iseq + 15;
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
    *(vm_base_ptr(reg_cfp) + 2) = stack[2];
    *(vm_base_ptr(reg_cfp) + 3) = stack[3];
    *(vm_base_ptr(reg_cfp) + 4) = stack[4];
    return Qundef;

} // end of _mjit1
