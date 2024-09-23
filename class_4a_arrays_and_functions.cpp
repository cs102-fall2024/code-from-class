/**
 * @file class_4a_ararys_and_functions.cpp
 * @author Sarah Morrison-Smith
 * @brief Demonstrates how arrays work with regards to functions
 * @version 0.1
 * @date 2024-09-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>

using namespace std;
const int DAYS = 7;

/**
 * @brief Changes the value of an array element based on user input
 * 
 * @param array The array to be modified
 */
void change_array(int array[]){
    int index;
    int value;
    cout << "What index do you want to change? ";
    cin >> index;
    cout << "What value do you want? ";
    cin >> value;

    array[index] = value;

}

/**
 * @brief Prints an array of ints
 * 
 * @param array The array to be printed
 * @param size The length of the array
 */
void print_int_array(const int array[], int size){
    cout << "{";
    for (int i = 0; i < size - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[size - 1] << "}" << endl;
}

// Runs the program
int main() {
    int temperatures[DAYS] = {66, 70, 65, 71, 72, 73, 72};
    print_int_array(temperatures, DAYS);

    change_array(temperatures);
    print_int_array(temperatures, DAYS);
}