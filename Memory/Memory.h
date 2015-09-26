//
// Created by max on 26.09.15.
//

#ifndef LAB1_MEMORY_H
#define LAB1_MEMORY_H

#include <vector>
#include <iostream>
using namespace std;

class Memory {
public: class Memory_unit_info {
        int addr;
        int size;
    };

    class Memory_unit {
        int memory;
    };

    vector<Memory_unit_info> info;
};


#endif //LAB1_MEMORY_H
