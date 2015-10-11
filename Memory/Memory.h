//
// Created by max on 26.09.15.
//

#ifndef LAB1_MEMORY_H
#define LAB1_MEMORY_H

#include <vector>
#include <iostream>

using namespace std;

class Memory {
    struct pages_with_state_3_block {
        uint16_t start_idx;
        uint16_t number_of_pages;

        pages_with_state_3_block(uint16_t start_idx, uint16_t number_of_pages) : start_idx(start_idx),
                                                                                 number_of_pages(number_of_pages) { }
    };

    class Page {
    public:
        uint16_t page_size;
        uint8_t state = 0;  // 0 - free; 2 - divided to blocks; 3 - whole in use
        uint16_t block_size = 0;
        uint16_t blocks_count = 1;

        vector<uint16_t> in_use_blocks_info;


        Page(const uint16_t page_size) {
            this->page_size = page_size;
//            memory_block = vector<Memory_unit>((unsigned long) (page_size / 4));
        }

        void split_to_blocks(uint16_t block_length) {
            uint16_t page_size_copy = page_size;
            while (2 <= page_size_copy) {
                if (page_size_copy < block_length) {
                    page_size_copy *= 2;
                    break;
                }
                page_size_copy /= 2;
            }

            this->block_size = page_size_copy;
            blocks_count = page_size / page_size_copy;
            in_use_blocks_info = vector<uint16_t>();
            state = 2;
        }

        bool have_free_block() {
            return (blocks_count != in_use_blocks_info.size());
        }
    };

    class Memory_unit {
        int memory;

    public:
        void operator=(const Memory_unit &unit) {
            this->memory = unit.memory;
        }
    };

public:
    // Memory
    vector<Page> pages;
    vector<pages_with_state_3_block> pages_blocks;

    vector<Memory_unit> memory_block;



    // Returns size aligned to 4B
    uint32_t size_with_align_4B(uint32_t size);

    uint16_t offset(uint16_t page, uint16_t block);

public:
    // Returns index of memory start from addr
    long what_number_am_i(void *addr);

    Memory(uint16_t pages_number, uint16_t page_size);

    // Allocates memory. If cannot returns NULL
    void *mem_alloc(size_t size);

    // Reallocates memory. Firstly tries to extend current block and if unsuccessful to find new
    void *mem_realloc(void *addr, size_t size);

    // Make memory free
    void mem_free(void *addr);

    // Prints memory info. '_' - free byte, '*' - byte in use
    void mem_dump();
};


#endif //LAB1_MEMORY_H
