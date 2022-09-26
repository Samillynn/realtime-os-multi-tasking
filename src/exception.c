//
// Created by 28379 on 9/25/2022.
//
#include "exception.h"
#include "printf.h"

#define EXCEPTION_CLASS_OFFSET 26
#define SVC_CLASS 0x15

u64 (*exception_handlers[1 << 16 ])(void);

void handle_exception(u64 esr) {
    u8 exception_class = (esr >> EXCEPTION_CLASS_OFFSET);
    if (exception_class == SVC_CLASS) {
        u16 imm = esr;
        get_current_task()->x[0] = exception_handlers[imm]();
    } else {
        printf("Unsupported exception class: %d\n", exception_class);
    }

    return;
}
