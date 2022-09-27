#include "kernel.h"
#include "common.h"
#include "rpi.h"
#include "memory.h"
#include "printf.h"

void boot() {
  init_gpio();
  init_spi(0);
  init_uart(0);
  printf("Init I/O\r\n");

  memory_init();
  printf("Init memory\r\n");
}

void kmain() {
  bool looping = true;
  
  while (looping) {
    
  }
}
