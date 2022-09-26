#include "kernel.h"
#include "common.h"
#include "rpi.h"
#include "memory.h"
#include "task.h"
#include "task_scheduler.h"

void boot() {
  init_gpio();
  init_spi(0);
  init_uart(0);

  memory_init();
}

void kmain() {
  bool looping = true;
  
  while (looping) {
    Task* current_task = schedule();
  }
}
