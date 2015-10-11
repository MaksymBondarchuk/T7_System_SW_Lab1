#include <iostream>
#include "Memory/Memory.h"

using namespace std;

int main() {
    Memory m = Memory(6, 32);

//    void *r0 = m.mem_alloc(32 * 2);
//    m.mem_dump();
//    void *r1 = m.mem_alloc(34);
//    m.mem_dump();
    void *r2 = m.mem_alloc(16);
    m.mem_dump();
    void *r3 = m.mem_alloc(8);
    m.mem_dump();
    void *r4 = m.mem_alloc(16);
    m.mem_dump();
    m.mem_free(r2);
    m.mem_dump();
    m.mem_free(r4);
    m.mem_dump();

//    void *r5 = m.mem_alloc(8);
//    void *r6 = m.mem_alloc(8);
//    void *r7 = m.mem_alloc(8);
//
//    Memory::mem_location ml0 = m.what_number_am_i(r0);
//    Memory::mem_location ml1 = m.what_number_am_i(r1);
//    Memory::mem_location ml2 = m.what_number_am_i(r2);
//    Memory::mem_location ml3 = m.what_number_am_i(r3);
//    Memory::mem_location ml4 = m.what_number_am_i(r4);
//    Memory::mem_location ml5 = m.what_number_am_i(r5);
//    Memory::mem_location ml6 = m.what_number_am_i(r6);
//    Memory::mem_location ml7 = m.what_number_am_i(r7);
//    cout << ml0.page << "  " << ml0.block << endl;
//    cout << ml1.page << "  " << ml1.block << endl;
//    cout << ml2.page << "  " << ml2.block << endl;
//    cout << ml3.page << "  " << ml3.block << endl;
//    cout << ml4.page << "  " << ml4.block << endl;
//    cout << ml5.page << "  " << ml5.block << endl;
//    cout << ml6.page << "  " << ml6.block << endl;
//    cout << ml7.page << "  " << ml7.block << endl;

//    cout << sizeof(m.pages[0]) << endl;
//    cout << sizeof(m.pages[1]) << endl;
//    cout << m.what_number_am_i(r1) << endl;




//    m.mem_dump();
//    void *ref0 = m.mem_alloc(16);
//    m.mem_dump();
//    void *ref1 = m.mem_alloc(3);
//    m.mem_dump();
//    m.mem_alloc(3);
//    m.mem_dump();
//    m.mem_realloc(ref0, 25);
//    m.mem_dump();
//    m.mem_free(ref1);
//    m.mem_dump();

    return 0;
}