/**
 * @file class_4b_arrays_pointers.cpp
 * @author Sarah Morrison-Smith
 * @brief Illustrates arrays and pointers
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Changes the value stored at this memory location
 * 
 * @param ptr The address of the int we want to change to 10
 */
void change_value(int* ptr) {
    *ptr = 10;
}

void print_int_array(int* arr, int size) {
    for (int i = 0; i < size; i ++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}


//Runs our program
int main() {
    int x = 5;
    cout << x << endl;
    change_value(&x);
    cout << x << endl;

    int my_array[6] = {1,5,27,81,39,40};
    int* array_ptr = my_array;

    cout << my_array << endl;
    cout << &my_array[0] << endl;
    cout << *my_array << endl;

    cout << *array_ptr << endl;
    array_ptr++;
    cout << *array_ptr << endl;

    // loop through array using pointers
    for (int i = 0; i < 6; i ++) {
        cout << array_ptr << " " << *array_ptr << endl; //derefrencing to get the value
        array_ptr++;
    }
    cout << my_array[2] << endl;
    cout << *(array_ptr + 2) << endl;

    print_int_array(my_array, 6);

}