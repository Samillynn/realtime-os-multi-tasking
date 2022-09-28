#include "kernel_syscall.h"
#include "task.h"
#include "task_scheduler.h"

// TODO: what if created by kernel
i32 sys_create() {
    Task * current_task = get_current_task();

    if (current_task == NULL) {
        return -1;
    }

    int priority = current_task->x[0];
    u64 func_ptr = current_task->x[1];

    Task * new_task = create_task(priority);
    new_task->x[30] = (u64) Exit;
    new_task->pc = func_ptr;
    return new_task->tid;
}

i32 sys_tid() {
    Task * current_task = get_current_task();

    if (current_task) {
        return current_task->tid;
    }

    return -1;
}

i32 sys_parent_tid() {
    Task * current_task = get_current_task();

    if (current_task) {
        return current_task->parent_tid;
    }

    return -1;
}

void sys_yield() {
    // do nothing
}

void sys_exit() {
    remove_current_task();
}


