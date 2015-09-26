//
// Created by max on 26.09.15.
//

#include "Memory.h"

Memory::Memory(size_t size) {
    info_free = vector<Memory_unit_info>();
    info_free.push_back(new Memory_unit_info(0, size));

    info_in_use = vector<Memory_unit_info>();

    memory_block = vector<Memory_unit>((unsigned long) size);
}

void *Memory::mem_alloc(size_t size) {
    for (int i = 0; i < info_free.size(); i++)
        if (size <= info_free[i].size) {
            info_in_use.push_back(new Memory_unit_info(info_in_use[i].addr, size));
            if (info_free[i].size == size) {
                info_free.erase(info_free.begin() + i);
                info_free[i].addr += size;
            }
            else
                info_free[i].size -= size;

            void *ret;
            return (void *) memory_block[info_in_use[info_in_use.size() - 1].addr];
//            return info_in_use[info_in_use.size() - 1].addr;
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

//int Memory::find_free_space(size_t size) {
//    for (int i = 0; i < info_free.size(); i++)
//        if (size <= info_free[i].size) {
//            info_in_use.push_back(new Memory_unit_info(info_in_use[i].addr, size));
//            if (info_free[i].size == size) {
//                info_free.erase(info_free.begin() + i);
//                info_free[i].addr += size;
//            }
//            else
//                info_free[i].size -= size;
//            return info_in_use[info_in_use.size() - 1].addr;
//        }
//
//    return -1;
//}
