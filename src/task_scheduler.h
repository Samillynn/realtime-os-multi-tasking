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

Task* create_task(u8 priority);
void remove_current_task();
Task* get_current_task();

Task* schedule();

#endif
