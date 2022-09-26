#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "common.h"

extern u64 Create(i32 priority, void (*function)());
extern u64 MyTid();
extern u64 MyParentTid();
extern void Yield();
extern void Exit();

#endif