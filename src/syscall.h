//
// Created by 28379 on 9/25/2022.
//

#ifndef CS452_K1_KSYSTEM_CALLS_H
#define CS452_K1_KSYSTEM_CALLS_H

#include "common.h"
#include "task.h"
#include "usyscall.h"

extern Task * current_task;

u64 kCreate();
u64 kMyTid();
u64 kMyParentTid();
void kYield();
void kExit();


#endif //CS452_K1_KSYSTEM_CALLS_H
