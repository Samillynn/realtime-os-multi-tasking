#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "common.h"

i32 Create(i32 priority, void (*function)());
i32 MyTid();
i32 MyParentTid();
void Yield();
void Exit();

#endif
