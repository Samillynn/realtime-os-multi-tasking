#include "common.h"
#include "task.h"
#include "printf.h"
#define EXCEPTION_CLASS_OFFSET 26
#define SVC_CLASS 0b010101

extern Task* current_task;

extern u64 (*exception_handlers[1 << 16])(void);

void handle_exception(u64 esr);