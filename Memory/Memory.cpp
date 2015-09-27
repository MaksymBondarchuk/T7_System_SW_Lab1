//
// Created by max on 26.09.15.
//

#include "Memory.h"
#include <iomanip>

Memory::Memory(size_t size) {
    info_free = vector<Memory_unit_info>();
//    Memory_unit_info mui = Memory_unit_info(0, size);
    info_free.push_back(Memory_unit_info(0, size));

    info_in_use = vector<Memory_unit_info>();

    memory_block = vector<Memory_unit>((unsigned long) size);
}

void *Memory::mem_alloc(size_t size) {
    for (int i = 0; i < info_free.size(); i++)
        if (size <= info_free[i].size) {
            info_in_use.push_back(Memory_unit_info(info_free[i].addr, size));
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
    if (addr == NULL)
        return mem_alloc(size);

    // Trying enhance block
    long idx = what_number_am_i(addr);
    size_t my_size = 0;
    int used_idx = 0;
    for (int i = 0; i < info_in_use.size(); i++)
        if (info_in_use[i].addr == idx) {
            my_size = (int) info_in_use[i].size;
            used_idx = i;
        }
    size_t size_minus_my_size = size - my_size;
    for (int i = 0; i < info_free.size(); i++)
        if (info_free[i].addr == idx + size && size_minus_my_size <= info_free[i].size) {
            info_in_use[used_idx].size += size_minus_my_size;
            if (info_free[i].size == size_minus_my_size)
                info_free.erase(info_free.begin() + i);
            else {
                info_free[i].addr += size_minus_my_size;
                info_free[i].size -= size_minus_my_size;
            }
        }

    // If cannot enhance current block
    for (int i = 0; i < info_free.size(); i++)
        if (size <= info_free[i].size) {
            info_in_use.push_back(Memory_unit_info(info_free[i].addr, size));
            if (info_free[i].size == size)
                info_free.erase(info_free.begin() + i);
            else {
                info_free[i].addr += size;
                info_free[i].size -= size;
            }

            mem_free(addr);

            for (int j = 0; j < info_in_use.size(); j++)
                if (info_in_use[j].addr == idx)
                    info_in_use.erase(info_in_use.begin() + j);

            return &memory_block[info_in_use[info_in_use.size() - 1].addr];
        }

    return NULL;
}

void Memory::mem_free(void *addr) {
    long idx = what_number_am_i(addr);
    for (int i = 0; i < info_in_use.size(); i++)
        if (idx == info_in_use[i].addr) {
            info_free.push_back(Memory_unit_info(info_in_use[i].addr, info_in_use[i].size));
            info_in_use.erase(info_in_use.begin() + i);
        }
}

void Memory::mem_dump() {
    int i = 0;
    while (i < memory_block.size()) {
        for (int j = 0; j < info_free.size(); j++)
            if (info_free[j].addr == i) {
                cout << string(info_free[j].size, '_');
                i += info_free[j].size;
            }

        for (int j = 0; j < info_in_use.size(); j++)
            if (info_in_use[j].addr == i) {
                cout << string(info_in_use[j].size, '*');
                i += info_in_use[j].size;
            }
    }
    cout << endl;
}

long Memory::what_number_am_i(void *addr) {
    if (addr == NULL)
        return -1;
    return ((long) addr - (long) &memory_block[0]) / sizeof(Memory_unit);
}
