//
// Created by 28379 on 9/25/2022.
//

#include "syscall.h"

u64 kCreate() {
    int priority = current_task->x[0];
    void (*function)() = current_task->x[1];

    Task* new_task = ?;
    new_task->x[30] = (u64)Exit;
    new_task->parent_tid = current_task->tid;

    // push the new task to kernel ready priority queue
}

u64 kMyTid() {
    return current_task->tid;
}

u64 kMyParentTid() {
    return current_task->parent_tid;
}

void kYield() {
    // do nothing
}

void kExit() {
    // remove the current task from kernel pq
}
