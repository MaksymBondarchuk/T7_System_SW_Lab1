#include <iostream>
#include "Memory/Memory.h"

using namespace std;

int main() {
    Memory m = Memory(6, 32);

    void *r0 = m.mem_alloc(32 * 2);
    m.mem_dump();
    void *r1 = m.mem_alloc(34);
    m.mem_dump();
    void *r2 = m.mem_alloc(16);
    m.mem_dump();
    void *r3 = m.mem_alloc(8);
    m.mem_dump();
    void *r4 = m.mem_alloc(16);
    m.mem_dump();

    m.mem_realloc(r4, 17);
    m.mem_dump();
    m.mem_free(r2);
    m.mem_dump();
    m.mem_free(r4);
    m.mem_dump();

    return 0;
}