//
// Created by 28379 on 9/25/2022.
//

#include "init.h"
#include "syscall.h"

void init_exception_handlers() {
    exception_handlers[1] = kCreate;
    exception_handlers[2] = kYield;
    exception_handlers[3] = kExit;
    exception_handlers[11] = MyTid;
    exception_handlers[12] = MyParentTid;
}

void init_first_user_task() {
    Task* task = ?;
    task->parent_tid = 0;
    task->priority = ?;
    // push to pq
}
