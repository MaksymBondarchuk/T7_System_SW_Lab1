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

    cout << m.what_number_am_i(r0) << "  " << r0 << endl;
    cout << m.what_number_am_i(r1) << "  " << r1 << endl;
    cout << m.what_number_am_i(r2) << "  " << r2 << endl;
    cout << m.what_number_am_i(r3) << "  " << r3 << endl;
    cout << m.what_number_am_i(r4) << "  " << r3 << endl;

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