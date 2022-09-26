.text
.global init
.align 4

init:
    adr x0, vector_table
    msr vbar_el2, x0
    bl init_exception_handlers
    bl init_first_user_task
