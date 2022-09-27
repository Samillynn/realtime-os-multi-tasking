.text
.global init_vector_table
.align 4

init_vector_table:
    adr x0, vector_table
    msr vbar_el1, x0
    ret
