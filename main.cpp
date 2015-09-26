#include <iostream>
#include <iomanip>
#include "Memory/Memory.h"

using namespace std;

int main() {
    Memory m = Memory(128);
    void *ref = m.mem_alloc(12);
    void *ref1 = m.mem_alloc(45);
    void *ref2 = m.mem_alloc(200);

    cout << m.what_number_am_i(ref) << endl;
    cout << m.what_number_am_i(ref1) << endl;
    cout << m.what_number_am_i(ref2) << endl;

    return 0;
}