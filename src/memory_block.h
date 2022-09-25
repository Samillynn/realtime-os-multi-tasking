#ifndef __MEMORY_BLOCK_H__
#define __MEMORY_BLOCK_H__

#include "common.h"

STRUCT(MemoryBlock) {
  u64 address;
  MemoryBlock* next;
};

#endif
