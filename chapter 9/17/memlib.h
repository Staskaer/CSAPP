/* $begin memlibheader */
#ifndef MEMLIB_H_
#define MEMLIB_H_

#include <unistd.h>

void mem_init(void);
void *mem_sbrk(int incr);

void mem_deinit(void);
void mem_reset_brk(void);
void *mem_heap_lo(void);
void *mem_heap_hi(void);
size_t mem_heapsize(void);
size_t mem_pagesize(void);
/* $end memlibheader */

#endif