#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "common.h"

u64 Create(i32 priority, void (*function)());
u64 MyTid();
u64 MyParentTid();
void Yield();
void Exit();

#endif
