#include <iostream>
#include "Memory/Memory.h"

using namespace std;

int main() {
    Memory m = Memory(17, 32);

    void *r0 = m.mem_alloc(32 * 3);
    void *r1 = m.mem_alloc(34);

    cout << m.what_number_am_i(r0) << "  " << r0 << endl;
    cout << m.what_number_am_i(r1) << "  " << r1 << endl;

    cout << sizeof(m.pages[0]) << endl;
    cout << sizeof(m.pages[1]) << endl;
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