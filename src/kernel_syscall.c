//
// Created by 28379 on 9/25/2022.
//

#include "kerenel_syscall.h"
#include "task_scheduler.h"

u64 sys_create() {
    Task* current_task = get_current_task();
    int priority = current_task->x[0];
    u64 func_ptr = current_task->x[1];

    Task* new_task = create_task(priority);
    new_task->x[30] = (u64)Exit;
    new_task->pc = func_ptr;
    return new_task->tid;
}

u64 sys_tid() {
    return get_current_task()->tid;
}

u64 sys_parent_tid() {
    return get_current_task()->parent_tid;
}

void sys_yield() {
    // do nothing
}

void sys_exit() {
    remove_current_task();
    // do not need to schedule here
}
