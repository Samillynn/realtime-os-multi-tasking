#include "kernel.h"
#include "common.h"
#include "rpi.h"
#include "memory.h"

void boot() {
  init_gpio();
  init_spi(0);
  init_uart(0);

  memory_init();
}

void kmain() {
  bool looping = true;
  
  while (looping) {
    
  }
}
