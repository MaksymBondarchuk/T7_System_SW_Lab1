//
// Created by max on 26.09.15.
//

#include "Memory.h"

Memory::Memory(size_t size) {
    info_free = vector<Memory_unit_info>();
    Memory_unit_info mui = Memory_unit_info(0, size);
    info_free.push_back(mui);

    info_in_use = vector<Memory_unit_info>();

    memory_block = vector<Memory_unit>((unsigned long) size);
}

void *Memory::mem_alloc(size_t size) {
    for (int i = 0; i < info_free.size(); i++)
        if (size <= info_free[i].size) {
            Memory_unit_info mui = Memory_unit_info(info_free[i].addr, size);
            info_in_use.push_back(mui);
            if (info_free[i].size == size)
                info_free.erase(info_free.begin() + i);
            else {
                info_free[i].addr += size;
                info_free[i].size -= size;
            }

            return &memory_block[info_in_use[info_in_use.size() - 1].addr];
        }

    return NULL;
}

void *Memory::mem_realloc(void *addr, size_t size) {
    return nullptr;
}

void Memory::mem_free(void *addr) {

}

void Memory::mem_dump() {

}

long Memory::what_number_am_i(void *addr) {
    if (addr == NULL)
        return -1;
    return ((long) addr - (long)&memory_block[0]) / sizeof(Memory_unit);
}
