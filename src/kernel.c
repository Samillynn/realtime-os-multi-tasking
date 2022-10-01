#include "kernel.h"
#include "common.h"
#include "rpi.h"
#include "memory.h"
#include "printf.h"
#include "task_scheduler.h"
#include "exception.h"

u64 _kernel_regs[31];
u64* kernel_regs = _kernel_regs;

void boot() {
    init_gpio();
    init_spi(0);
    init_uart(0);
    printf("Init I/O\r\n");

    memory_init();
    printf("Init memory\r\n");
    task_queue_init();
    printf("Init task queue\r\n");
}

void kmain() {
    bool looping = true;

    while (looping) {

    }
}
