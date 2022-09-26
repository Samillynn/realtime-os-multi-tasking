#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "common.h"

#define EXCEPTION_CLASS_OFFSET 26
#define SVC_CLASS 0x15

u64 (*exception_handlers[1 << 16])(void);

void handle_exception(u64 esr);

#endif
