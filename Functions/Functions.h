//
// Created by max on 26.09.15.
//

#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H

#include <stddef.h>

void *mem_alloc(size_t size);

void *mem_realloc(void *addr, size_t size);

void mem_free(void *addr);

void mem_dump();

#endif //LAB1_FUNCTIONS_H
