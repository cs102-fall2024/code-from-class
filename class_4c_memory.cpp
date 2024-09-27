/**
 * @file class_4c_memory.cpp
 * @author Sarah Morrison-Smith
 * @brief Dynamic memory allocation!
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Create a array object
 * 
 * @param size - the size of the array
 * @return int* - the pointer to the array a.k.a the array name
 */
int* create_array(int size) {
    int* my_array = new int[size];//allocating an array on the heap

    //Initialize array with some values
    for (int i =0; i < size; i++) {
        my_array[i] = i * 2;
    }

    return my_array;
}

void create_leak() {
    int* leak_array = new int[100]; //dynamically allocate an array that is never deleted
    delete[] leak_array;
}

int* create_another_leak() {
    int* leak_array = new int[100]; //dynamically allocate an array that is never deleted
    return leak_array;
}

int main() {
    /*int* ptr = new int; //"new" allocates memory for an single integer
    *ptr = 10; //assign a value to our dynamically allocated memory

    //delete ptr; // deallocating from memory the integer
    cout << "Ptr address: " << ptr << endl;
    cout << "Value of ptr: " << *ptr << endl;
    delete ptr; // deallocating from memory the integer*/
    

    /*int my_array[6];
    for (int i = 0; i < 6; i++) {
        cout << my_array[i] << endl;
    }*/

    /*int* cats = new int[10]; //Dynamically allocating an array of 10 integers
    cats[3] = 2; //setting hte 4th element, the one with the index of 3 to be 2
    cout << cats[3] << endl;*/

    /**int size;
    cout << "Enter the size of the array: ";
    cin >> size; //user inputs the size of the array at runtime
    int* dogs = new int[size]; //dynamically allocate the array based on input size
    int first;
    cout << "Enter the first element in the array: ";
    cin >> first;
    dogs[0] = first;
    cout << dogs[0] << endl;**/

    /*int size = 5;
    int* my_new_array = create_array(size);// get that array

    //print the array
    for (int i = 0; i < size; i++) {
        cout << my_new_array[i] << " ";
    }
    cout << endl;

    delete[] my_new_array;*/

    for (int i = 0; i < 1000; i++) { 
        //create_leak();
        int* arr = create_another_leak();
        delete[] arr;
    }
    return 0;
}

