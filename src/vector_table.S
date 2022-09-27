.text
.global vector_table
.extern exception_entry

.balign 0x800
vector_table:

.balign 0x80
sp0_svc:
    b handle_error
.balign 0x80
sp0_irq:
    b handle_error
.balign 0x80
sp0_fiq:
    b handle_error
.balign 0x80
sp0_serror:
    b handle_error

.balign 0x80
sp1_svc:
    b handle_error
.balign 0x80
sp1_irq:
    b handle_error
.balign 0x80
sp1_fiq:
    b handle_error
.balign 0x80
sp1_serror:
    b handle_error

.balign 0x80
low_el64_svc:
    b exception_entry
.balign 0x80
low_el64_irq:
    b handle_error
.balign 0x80
low_el64_fiq:
    b handle_error
.balign 0x80
low_el64_serror:
    b handle_error

.balign 0x80
low_el32_svc:
    b handle_error
.balign 0x80
low_el32_irq:
    b handle_error
.balign 0x80
low_el32_fiq:
    b handle_error
.balign 0x80
low_el32_serror:
    b handle_error





.balign 0x400
synchronous:
    b exception_entry
