#include <iostream>

using namespace std;

const int NUMBERS_SIZE = 6;
const int RGB_SIZE = 3;

/**
 * @brief Prints an array of ints in a nice format
 * 
 * Note: this function returns "void" which means it returns nothing
 * 
 * @param nums - an array of ints
 * @param size - the length of nums
 */
void print_ints(int nums[], int size) {
    cout << "{";
    for (int i = 0; i < size - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[size - 1] << "}" << endl;
}

// Runs the program
int main() {
    int numbers[NUMBERS_SIZE] = {32, -309, 349, 2394, -2};
    int rgb[RGB_SIZE] = {255, 0, 0};

    print_ints(numbers, NUMBERS_SIZE);
    print_ints(rgb, RGB_SIZE);
}