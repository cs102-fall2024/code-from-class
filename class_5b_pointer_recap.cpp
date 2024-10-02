/**
 * @file class_5b_pointer_recap.cpp
 * @author Sarah Morrison-Smith
 * @brief Review of Pointers
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

int main() {
    int a = 10;          // Declare an integer variable
    int* p = &a;         // Declare a pointer and assign it the address of 'a'
    
    std::cout << "Value of a: " << a << std::endl;       // Output: 10
    std::cout << "Address of a: " << &a << std::endl;    // Output: Address of 'a'
    std::cout << "Pointer p points to: " << p << std::endl;  // Output: Address of 'a'
    std::cout << "Value pointed to by p: " << *p << std::endl; // Output: 10 (dereferencing the pointer)
    
    *p = 20;            // Change the value of 'a' via the pointer
    std::cout << "New value of a: " << a << std::endl;   // Output: 20
}
