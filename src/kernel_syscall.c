#include "kernel_syscall.h"
#include "task.h"
#include "task_scheduler.h"

i32 sys_create(i32 priority) {
  Task* task = create_task(priority);

  if (task) {
    // TODO: set task descriptor
  }

  return 0; // TODO: return value?
}

i32 sys_tid() {
  Task* current_task = get_current_task();

  if (current_task) {
    return current_task->tid;
  }

  return -1;
}

i32 sys_parentTid() {
  Task* current_task = get_current_task();

  if (current_task) {
    return current_task->parent_tid;
  }

  return -1;
}

void sys_yield() {
  // TODO: implement sys_yield
}

void sys_exit() {
  remove_current_task();
}
