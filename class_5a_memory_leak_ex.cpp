/**
 * @file class_5a_memory_leak_ex.cpp
 * @author Sarah Morrison-Smith
 * @brief Creates a memory leak
 * @version 0.1
 * @date 2024-09-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

using namespace std;

const long NUM_LOOPS = 50000;
const long SIZE_ARRAY = 10000000000;

int main() {
    int* array_to_leak;

    for (int i = 0; i < NUM_LOOPS; i ++) {
        if (i % 1000 == 0)
            cout << i << endl;

            //Each time through the loop, we reassign array_to_leak to new memory
            //without deleting it first , meaning we are leaking memory!
            array_to_leak = new int[SIZE_ARRAY];

            //Note if we just deleted it every time, we wouldn't have a problem!
            delete[] array_to_leak;
    }
}