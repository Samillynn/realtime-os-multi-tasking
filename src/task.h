#ifndef __TASK_H__
#define __TASK_H__

#include "common.h"
#include "memory_block.h"

STRUCT(Task) {
  i32 tid;
  i32 parent_tid;
  u32 priority;

  u64 x[31];
  u64 sp;
  u64 spsr;
  u64 pc;

  MemoryBlock* memory_block;
  Task* next;
};

#endif
