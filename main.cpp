#include <iostream>
#include <iomanip>
#include "Memory/Memory.h"

using namespace std;

int main() {
    Memory m = Memory(12 + 46);
    m.mem_dump();
    void *ref0 = m.mem_alloc(3);
    void *ref1 = m.mem_alloc(3);
    void *ref2 = m.mem_alloc(3);
    void *ref3 = m.mem_alloc(3);
    m.mem_dump();
    m.mem_free(ref2);
    m.mem_dump();

    m.mem_realloc(ref1, 9);

//    cout << m.what_number_am_i(ref0) << endl;
//    cout << m.what_number_am_i(ref1) << endl;
//    cout << m.what_number_am_i(ref2) << endl;

    m.mem_dump();

    return 0;
}