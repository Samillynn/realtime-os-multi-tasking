//
// Created by 28379 on 9/25/2022.
//
#include "../src/task.h"
#include "../src/printf.h"

void print_task(Task* task) {
    printf("debug task %d\n", task);
    printf("tid=%d, pid=%d, priority=%d\n", task->tid, task->parent_tid, task->priority);
    for (int i = 0; i < 31; i++) {
        printf("reg[%d]=%d\n", i, task->x[i]);
    }
    printf("sp=%d, spsr=%d, pc=%d\n", task->sp, task->spsr, task->pc);
}
