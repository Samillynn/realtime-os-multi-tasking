#ifndef __TASK_H__
#define __TASK_H__

#include "common.h"
#include "memory_block.h"

#define TASK_PRIORITY_MIN 0
#define TASK_PRIORITY_MAX 10

STRUCT(Task) {
  i32 tid;
  i32 parent_tid;
  i32 priority;

  u64 x[31];
  u64 sp;
  u64 spsr;
  u64 pc;

  MemoryBlock* memory_block;
  Task* next;
};

void task_init(Task* self);

#endif
