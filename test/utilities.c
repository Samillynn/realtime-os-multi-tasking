//
// Created by 28379 on 9/25/2022.
//
#include "../src/task.h"
#include "../src/printf.h"
#include "../src/task_scheduler.h"

void print_task(Task *task) {
    printf("\r\nCalling print_task: %d\r\n", task);
    printf("tid=%d, pid=%d, priority=%d\r\n", task->tid, task->parent_tid, task->priority);
    for (int i = 0; i < 31; i++) {
        printf("reg[%d]=%d\r\n", i, task->x[i]);
    }
    printf("sp=%d, spsr=%d, pc=%d\r\n", task->sp, task->spsr, task->pc);
}

void print_current_task() {
    print_task(get_current_task());
}


void print_reg(u64 x, int code) {
    printf("Current Register(%d) is %d\r\n", code, x);
}