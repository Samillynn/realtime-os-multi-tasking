//
// Created by 28379 on 9/23/2022.
//

#include "assembly_macro.S"

.text
.global exception_entry
.align 4

exception_entry:

store_user_task:
    // store x0 to SP, so that x0 can be used temporarily
    str x0, [sp]

    // put &currentTask to x0
    ldr x0, =currentTask
    ldr x0, [x0]

    // save x1-x30 to currentTask
    sub x0, x0, 20
    save_x1_30

    // load original x0 to x1, and store to task descriptor
    ldr x1, [sp]
    str x1, [x0, #8]!

    // str sp, spsr, pc
    add x0, x0, #-248
    // TODO: may need to change SP_SEL
    str sp_el0, [x0], #-8
    str spsr, [x0], #-8
    str elr_el1, [x0], #-8

load_kernel_task:
    // put &kernelTask to x0
    ldr x0, =kernelTask
    ldr x0, [x0]

    // restore x1-x30 from kernelTask
    sub x0, x0, 20
    load_x1_30

    // restore x0
    ldr x0, [x0, #8]!

    b svc_entry

_svc:

