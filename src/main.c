#include "task.h"
#include "exception.h"
#include "syscall.h"
#include "init.h"
#include "kernel.h"
#include "user_tasks.h"

i32 main() {
    boot();
    printf("Boot successfully\r\n");

    printf("Start Program\r\n");
    init();
    while(1) {
        current_task = schedule();
        if (current_task != NULL) {
            int request = activate_current_task();
            handle_exception(request);
        } else {
            printf("All user tasks have finished, exit elegantly\r\n");
            return 0;
        }
    }
    printf("Kernel Program Exit\r\n");
}
