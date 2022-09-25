.text
.global vector_table
.extern exception_entry

.balign 0x800
// TODO: may be wrong since already aligned
vector_low_el_aarch64:
    .balign 0x400
synchronous:
    b exception_entry
