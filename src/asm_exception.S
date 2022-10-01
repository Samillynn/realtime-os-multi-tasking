#include "macro.S"
.text
.align 4
.global exception_entry

exception_entry:

leave_current_task:
    load_user_regs current_task

start_handle_exception:
    mrs x0, esr_el1
    bl handle_exception
    bl schedule


.align 4
.text
.global enter_current_task
/** @arg current_task **/
/** Context switch back to current_task **/

enter_current_task:
    load_user_regs current_task

    eret


.global handle_error
.align 4
handle_error:
    mrs x0, CurrentEL
    mrs x1, ELR_EL1
    mrs x2, ESR_EL1
    // mrs x3, ELR_EL2
    // mrs x4, ESR_EL2
    // bl print_error
    ret
