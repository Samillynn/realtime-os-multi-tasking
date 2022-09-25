//
// Created by 28379 on 9/23/2022.
//

.text
.global exception_entry
.align 4

exception_entry:

leave_current_task:
    // make sure that sp of current el is used
    msr spsel, 1

    // store x0 to SP, so that x0 can be used temporarily
    str x0, [sp]

    // put &currentTask to x0
    ldr x0, =current_task
    ldr x0, [x0]

    // save x1 to current_task
    add x0, x0, #-12
    stp x2, x1, [x0, #-16]

    // load x0 back to x1, and save x0 to current_task
    ldr x1, [sp]
    str x1, [x0], #-16

    // save x3 - x30
    stp x4, x3, [x0, #-16]!
    stp x6, x5, [x0, #-16]!
    stp x8, x7, [x0, #-16]!
    stp x10, x9, [x0, #-16]!
    stp x12, x11, [x0, #-16]!
    stp x14, x13, [x0, #-16]!
    stp x16, x15, [x0, #-16]!
    stp x18, x17, [x0, #-16]!
    stp x20, x19, [x0, #-16]!
    stp x22, x21, [x0, #-16]!
    stp x24, x23, [x0, #-16]!
    stp x26, x25, [x0, #-16]!
    stp x28, x27, [x0, #-16]!
    stp x30, x29, [x0, #-16]!

    // str sp
    msr spsel, #0
    str sp, [x0, #-8]!
    msr spsel, #1

    // str spsr
    mrs x1, spsr
    str x1, [x0, #-8]!

    // str pc
    mrs x1, elr_el1
    str x1, [x0, #-8]!

call_handle_exception:
    mrs x0 esr_el1
    bl handle_exception
    b _Reschedule


enter_current_task:
    // load regs
    ldr x0, =current_task
    ldr x0, [x0]

    // offset
    add x0, x0, #-12

    // load x1 - x30
    add x0, x0, #-8
    ldp x2, x1, [x0, #-16]!
    ldp x4, x3, [x0, #-16]!
    ldp x6, x5, [x0, #-16]!
    ldp x8, x7, [x0, #-16]!
    ldp x10, x9, [x0, #-16]!
    ldp x12, x11, [x0, #-16]!
    ldp x14, x13, [x0, #-16]!
    ldp x16, x15, [x0, #-16]!
    ldp x18, x17, [x0, #-16]!
    ldp x20, x19, [x0, #-16]!
    ldp x22, x21, [x0, #-16]!
    ldp x24, x23, [x0, #-16]!
    ldp x26, x25, [x0, #-16]!
    ldp x28, x27, [x0, #-16]!
    ldp x30, x29, [x0, #-16]!

    // load sp
    msr spsel, #0
    ldr sp, [x0, #-8]!
    msr spsel, #1

    // load spsr
    ldr x1, [x0, #-8]!
    msr spsr, x1

    // load pc
    ldr x1, [x0, #-8]!
    msr elr_el1, x1

    // load x0
    ldr x0, [x0, #(33*8)]!

    eret
