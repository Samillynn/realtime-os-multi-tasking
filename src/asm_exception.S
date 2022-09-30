#include "macro.S"
.macro save_user_regs var
    save_general_regs \var

    // save sp
    msr spsel, #0
    mov x1, sp
    str x1, [x0], #8
    msr spsel, #1

    // str spsr
    mrs x1, spsr_el1
    str x1, [x0], #8

    // str pc
    mrs x1, elr_el1
    str x1, [x0], #8
.endm

.macro load_user_regs var
    load_global x0, \var

    // load x1 - x30
    add x0, x0, #(8*31)

    // load sp
    msr spsel, #0
    ldr x1, [x0], #8
    mov sp, x1
    msr spsel, #1

    // load spsr
    ldr x1, [x0], #8
    msr spsr_el1, x1

    // load pc
    ldr x1, [x0], #8
    msr elr_el1, x1

    // load x30 to x0
    load_general_regs \var
.endm

.text
.align 4
.global exception_entry

// =================================== MACROS END HERE ================================== //

exception_entry:
    save_user_regs
    mrs x0, esr_el1
    bl handle_exception
    bl schedule

.align 4
.text
.global enter_current_task
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
