/**
 * @file class_5b_reference_variables.cpp
 * @author Sarah Morrison-Smith
 * @brief Reference Variable Recap
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

int main() {
    int a = 40;        // Declare an integer variable
    int& ref = a;      // Reference to variable 'a'
    
    std::cout << "Value of a: " << a << std::endl;     // Output: 40
    std::cout << "Value of ref (alias for a): " << ref << std::endl; // Output: 40
    
    ref = 50;          // Changing the value of 'ref' also changes 'a'
    std::cout << "New value of a: " << a << std::endl;  // Output: 50
    
    int b = 60;
    //ref = &b;       // This is illegal! You cannot rebind a reference.
}
