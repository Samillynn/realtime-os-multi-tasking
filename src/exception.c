//
// Created by 28379 on 9/25/2022.
//
#include "exception.h"
#include "rpi.h"
#include "task.h"
#include "task_scheduler.h"

void handle_exception(u64 esr) {
  Task* current_task = get_current_task();
  
  u8 exception_class = (esr >> EXCEPTION_CLASS_OFFSET);
  if (exception_class == SVC_CLASS) {
    u16 imm = esr;
    current_task->x[0] = exception_handlers[imm]();
  } else {
    uart_printf(0, 0, "Unsupported exception class: %d", exception_class);
  }

  return;
}
