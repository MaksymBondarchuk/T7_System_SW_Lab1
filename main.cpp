#include <iostream>
#include <iomanip>
#include "Memory/Memory.h"

using namespace std;

int main() {
    Memory m = Memory(64);
    m.mem_dump();
    void *ref0 = m.mem_alloc(16);
    void *ref1 = m.mem_alloc(3);
    void *ref2 = m.mem_alloc(3);
//    void *ref3 = m.mem_alloc(3);
//    m.mem_dump();
//    m.mem_free(ref2);
//    m.mem_dump();
//
    m.mem_dump();
//    m.mem_realloc(ref0, 7);
//    m.mem_dump();
//    m.mem_alloc(48 + 8);
    m.mem_free(ref1);
    m.mem_dump();
    m.mem_free(ref2);
    m.mem_dump();


    return 0;
}