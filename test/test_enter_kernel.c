//
// Created by 28379 on 9/25/2022.
//

#include "../src/task.h"
#include "../src/exception.h"
#include "../src/syscall.h"
#include "../src/init.h"


void initial_user_task() {
    printf("1: Tid: %d, ParentTid: %d\n", MyTid(), MyParentTid());
    Yield();
    printf("2: Tid: %d, ParentTid: %d\n", MyTid(), MyParentTid());
    Yield();
    printf("3: Tid: %d, ParentTid: %d\n", MyTid(), MyParentTid());
}

int main() {

    while(1) {
        printf("Start Program\n");
        init();
    }
}