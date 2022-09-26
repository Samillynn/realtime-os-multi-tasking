//
// Created by 28379 on 9/25/2022.
//

#include "../src/task_scheduler.h"
#include "utilities.h"
#include "../src/exception.h"

Task ct_ = {0};
Task* current_task = &ct_;

void task_queue_init();
void task_queue_add(Task* task);

Task* create_task(u8 priority) {
    printf("Mock Create task with p=%d, just return the current task\n", priority);
    print_task(current_task);
    return current_task;
}

void remove_current_task(){}
Task* get_current_task() {
    printf("Mock get_current_task\n");
    return current_task;
}

Task* schedule() {
    printf("Mock Scheduling\n");
    print_task(current_task);
    Task* task = get_current_task();
    print_task(task);
    enter_current_task();
}
