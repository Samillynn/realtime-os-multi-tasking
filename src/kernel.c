#include "kernel.h"
#include "common.h"
#include "rpi.h"
#include "memory.h"
#include "printf.h"
#include "task_scheduler.h"
#include "exception.h"

void boot() {
    handle_error();
    init_gpio();
    init_spi(0);
    init_uart(0);
    printf("Init I/O\r\n");
    handle_error();

    memory_init();
    printf("Init memory\r\n");
    handle_error();
    task_queue_init();
    handle_error();
    printf("Init task queue\r\n");
    handle_error();
}

void kmain() {
    bool looping = true;

    while (looping) {

    }
}
