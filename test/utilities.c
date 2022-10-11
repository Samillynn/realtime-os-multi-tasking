//
// Created by 28379 on 9/25/2022.
//
#include "../src/task.h"
#include "../src/printf.h"
#include "../src/task_scheduler.h"

void print_task(Task *task) {
//    printf("\r\nCalling print_task: %d\r\n", task);
//    printf("Tid=%d, Pid=%d, Priority=%d\r\n", task->tid, task->parent_tid, task->priority);
//    for (int i = 0; i < 3; i++) {
//        printf("reg[%d]=%d\r\n", i, task->x[i]);
//    }
//    for (int i = 0; i < 31; i++) {
//        printf("reg[%d]=%d\r\n", i, task->x[i]);
//    }
//    printf("sp=%x, spsr=%x, pc=%x\r\n", task->sp, task->spsr, task->pc);
}

void print_current_task() {
    print_task(get_current_task());
}


void print_reg(u64 x, int code) {
    printf("Current Register(%d) is %d\r\n", code, x);
}

