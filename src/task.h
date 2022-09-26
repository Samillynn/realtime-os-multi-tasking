#ifndef __TASK_H__
#define __TASK_H__

#include "common.h"
#include "memory_block.h"

STRUCT(Task) {
  u32 tid;
  u32 parent_tid;
  u32 priority;

  u64 x[31];
  u64 sp;
  u64 spsr;
  u64 pc;
  u64 result;

  MemoryBlock* address;
};

#endif
