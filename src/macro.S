#ifndef __MACRO_S__
#define __MACRO_S__
.macro save_general_regs var
    // store x0 to SP, so that x0 can be used temporarily
    str x0, [sp, #-16]!

    ldr x0, =\var
    ldr x0, [x0]
    add x0, x0, #8

    // save x1 - x30
    stp x1, x2, [x0], #16
    stp x3, x4, [x0], #16
    stp x5, x6, [x0], #16
    stp x7, x8, [x0], #16
    stp x9, x10, [x0], #16
    stp x11, x12, [x0], #16
    stp x13, x14, [x0], #16
    stp x15, x16, [x0], #16
    stp x17, x18, [x0], #16
    stp x19, x20, [x0], #16
    stp x21, x22, [x0], #16
    stp x23, x24, [x0], #16
    stp x25, x26, [x0], #16
    stp x27, x28, [x0], #16
    stp x29, x30, [x0], #16

    // save x0
    ldr x1, [sp], #16
    sub x0, x0, #(8*31)
    str x1, [x0], #(8*31)

.endm

.macro make_svc func_name svc_code
.text
.align 4
.global \func_name
\func_name:
    svc #\svc_code
    ret
.endm


#endif
