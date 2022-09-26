#ifndef __TASK_SCHEDULER_H__
#define __TASK_SCHEDULER_H__

#include "common.h"
#include "task.h"

STRUCT(TaskQueue) {
  Task* front;
  Task* end;
};

void task_queue_init();
void task_queue_add(Task* task);
Task* task_queue_pop();
Task* task_queue_peek();

Task* create_task(i32 priority);
void remove_current_task();
Task* get_current_task();

Task* schedule();

#endif
