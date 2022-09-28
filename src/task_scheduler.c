#include "task_scheduler.h"
#include "memory.h"
#include "utilities.h"
#include "exception.h"

#define TASK_POOL_SIZE  128

static Task task_pool[TASK_POOL_SIZE];
static Task* task_pool_ptr;
static TaskQueue task_queue[TASK_PRIORITY_MAX];

static i32 task_id_cnt;

static Task* current_task;

void task_queue_init() {
  current_task = NULL;

  for (usize i = 0; i < TASK_POOL_SIZE; i ++) {
    task_init(&task_pool[i]);
    if (i < TASK_POOL_SIZE - 1) {
      task_pool[i].next = &task_pool[i + 1];
    } else {
      task_pool[i].next = NULL;
    }
  }

  for (usize i = TASK_PRIORITY_MIN; i < TASK_PRIORITY_MAX; i ++) {
    task_queue[i].front = NULL;
    task_queue[i].end = NULL;
  }

  task_pool_ptr = &task_pool[0];

  task_id_cnt = 0;
}

void task_queue_add(Task* task) {
  i32 priority = task->priority;

  if (task_queue[priority].end) {
    task_queue[priority].end->next = task;
    task_queue[priority].end = task_queue[priority].end->next;
  } else {
    task_queue[priority].end = task;
    task_queue[priority].front = task;
  }

  task->next = NULL;
}

Task* task_queue_pop() {
  Task* popped = NULL;

  for (i32 i = TASK_PRIORITY_MAX - 1; i >= TASK_PRIORITY_MIN; i --) {
    if (task_queue[i].front) {
      popped = task_queue[i].front;
      if (task_queue[i].front->next) {
	task_queue[i].front = task_queue[i].front->next;
      } else {
	task_queue[i].front = NULL;
	task_queue[i].end = NULL;
      }
      break;
    }
  }

  return popped;
}

Task* task_queue_peek() {
  Task* task = NULL;

  for (i32 i = TASK_PRIORITY_MAX - 1; i >= TASK_PRIORITY_MIN; i --) {
    if (task_queue[i].front) {
      task = task_queue[i].front;
      break;
    }
  }

  return task;
}

Task* create_task(i32 priority) {
  priority = i32_clamp(priority, TASK_PRIORITY_MIN, TASK_PRIORITY_MAX - 1);
  Task* task = NULL;

  if (task_pool_ptr) { // TODO: check priority range
    task = task_pool_ptr;
    task_pool_ptr = task->next;

    task_init(task);
    
    task->tid = task_id_cnt;
    task_id_cnt += 1;
    if (current_task) {
      task->parent_tid = current_task->tid;
    } else {
      task->parent_tid = -1;
    }
    task->priority = priority;

    task->sp = task->memory_block->address;
    
    task->memory_block = memory_allocate_block();
    task->next = NULL;

    task_queue_add(task);
  }

  return task;
}

void remove_current_task() {
  memory_free_block(current_task->memory_block);

  task_init(current_task);
  current_task = NULL;
}

Task* get_current_task() {
  return current_task;
}

Task* schedule() {
  if (current_task) {
    task_queue_add(current_task);
  }
  current_task = task_queue_pop();

  return current_task;
}
