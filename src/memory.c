#include "memory.h"

#define STACK_TOP 0x200000
#define MEMORY_BLOCK_SIZE 0x10000

static MemoryBlock memory_blocks[MEMORY_BLOCK_MAX_NUM];
static MemoryBlock* memory_blocks_ptr;

void memory_init() {
  u64 ptr = STACK_TOP;
  MemoryBlock* current = NULL;

  for (usize i = 0; i < MEMORY_BLOCK_MAX_NUM; i ++) {
    ptr += MEMORY_BLOCK_SIZE;
    memory_blocks[i].address = ptr;
    memory_blocks[i].next = current;
    current = &memory_blocks[i];
  }

  memory_blocks_ptr= current;
}

MemoryBlock* memory_allocate_block() {
  if (!memory_blocks_ptr) return NULL;

  MemoryBlock* memory_block = memory_blocks_ptr;
  memory_blocks_ptr = memory_blocks_ptr->next;

  memory_block->next = NULL;
  return memory_block;
}

void memory_free_block(MemoryBlock* memory_block) {
  memory_block->next = memory_blocks_ptr;
  memory_blocks_ptr = memory_block;
}
