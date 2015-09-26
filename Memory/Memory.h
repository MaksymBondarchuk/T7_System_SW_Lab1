//
// Created by max on 26.09.15.
//

#ifndef LAB1_MEMORY_H
#define LAB1_MEMORY_H

#include <vector>
#include <iostream>
using namespace std;

class Memory {
    struct Memory_unit_info {
        int addr;
        size_t size;

        Memory_unit_info(int addr, size_t size) : size(size), addr(addr) { }
    };

    class Memory_unit {
        int memory;
    };

    vector<Memory_unit_info> info_free;
    vector<Memory_unit_info> info_in_use;

    vector<Memory_unit> memory_block;


public:
    Memory(size_t size);

    void *mem_alloc(size_t size);

    void *mem_realloc(void *addr, size_t size);

    void mem_free(void *addr);

    void mem_dump();

    long what_number_am_i(void *addr);
};


#endif //LAB1_MEMORY_H
