//
// Created by 28379 on 9/25/2022.
//

#include "../src/task.h"
#include "../src/exception.h"
#include "../src/syscall.h"
#include "../src/init.h"
#include "../src/kernel.h"

void initial_user_task() {
    printf("Enter first user task\r\n");
    printf("MyId: %d\r\n", MyTid());
    printf("MyParentId: %d\r\n", MyParentTid());
    Yield();
    printf("2: Tid: %d, ParentTid: %d\r\n", MyTid(), MyParentTid());
    Yield();
    printf("3: Tid: %d, ParentTid: %d\r\n", MyTid(), MyParentTid());
    printf("Exiting first user task\r\n");
}

int main() {
    boot();

    while(1) {
        printf("Start Program\r\n");
        init();
    }
}