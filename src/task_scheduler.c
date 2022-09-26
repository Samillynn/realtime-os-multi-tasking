#include "task_scheduler.h"
#include "memory.h"

#define TASK_POOL_SIZE  32
#define TASK_QUEUE_SIZE 32

static Task task_pool[TASK_POOL_SIZE];
static Task* task_pool_ptr;
static TaskQueue task_queue[TASK_QUEUE_SIZE];

static i32 task_id_cnt;

static Task* current_task;

void task_queue_init() {
  current_task = NULL;

  for (usize i = 0; i < TASK_POOL_SIZE; i ++) {
    if (i < TASK_POOL_SIZE - 1) {
      task_pool[i].next = &task_pool[i + 1];
    } else {
      task_pool[i].next = NULL;
    }
  }

  for (usize i = 0; i < TASK_QUEUE_SIZE; i ++) {
    task_queue[i].front = NULL;
    task_queue[i].end = NULL;
  }

  task_pool_ptr = &task_pool[0];

  task_id_cnt = 0;
}

void task_queue_add(Task* task) {
  (void)task;
  // TODO: implement task_queue_add
}

Task* create_task(u8 priority) {
  Task* task = NULL;

  if (task_pool_ptr) { // TODO: check priority range
    task = task_pool_ptr;
    task_pool_ptr = task->next;
    
    task->tid = task_id_cnt;
    task_id_cnt += 1;
    task->parent_tid = current_task ? -1 : current_task->tid;
    task->priority = priority;

    for (usize i = 0; i < 31; i ++) {
      task->x[i] = 0;
    }
    task->sp = task->memory_block->address;
    task->spsr = 0;
    task->pc = 0;
    
    task->memory_block = memory_allocate_block();
    task->next = NULL;

    task_queue_add(task);
  }

  return task;
}

void remove_current_task() {
  memory_free_block(current_task->memory_block);

  current_task->tid = 0;
  current_task->parent_tid = -1;
  current_task->priority = 0;
  for (usize i = 0; i < 31; i ++) {
    current_task->x[i] = 0;
  }
  current_task->sp = 0;
  current_task->spsr = 0;
  current_task->pc = 0;
  current_task->memory_block = NULL;
  current_task = NULL;
}

Task* get_current_task() {
  return current_task;
}

Task* schedule() {
  // TODO: implement schedule
  return NULL;
}
