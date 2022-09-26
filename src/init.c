//
// Created by 28379 on 9/25/2022.
//

#include "init.h"
#include "kerenel_syscall.h"
#include "user_tasks.h"

void init_exception_handlers() {
    exception_handlers[1] = sys_create;
    exception_handlers[2] = sys_yield;
    exception_handlers[3] = sys_exit;
    exception_handlers[11] = sys_tid;
    exception_handlers[12] = sys_parent_tid;
}

void init_first_user_task() {
    printf("Initializing first user task");
    Task* task = create_task(INITIAL_PRIORITY);
    task->pc = (u64)initial_user_task;
    // start to run user programs
    schedule();
}
