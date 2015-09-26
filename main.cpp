#include <iostream>
#include "Memory/Memory.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Memory m = Memory();
    Memory::Memory_unit mu = Memory::Memory_unit();
    cout << sizeof(mu) << endl;

    return 0;
}