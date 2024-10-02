/**
 * @brief Examples of static vs constant
 * @file class_5b_constants.cpp
 */

const int x =  10; //stored on data segment, global scope, does not change
static const int h = 30; //stored on data segment (read only part), file scope, does not change
static int global = 8; //stored on data segment (read AND write), global scope, can change

void my_function() {
    static int b = 4; //stored on data segment, local scope, can change
    static const int z = 20; //stored on the data segment (read only part), local scope, does not change

}

int main() {
    const int y = 5; //stored on stack, local scope, does not change
    static int a = 6; //stored on the data segment, local scope, can change

}