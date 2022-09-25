#include "common.h"
#include "kernel.h"

i32 main() {
  boot();
  kmain();
  
  return 0;
}
