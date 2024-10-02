/**
 * @file class_5b_advanced_pointers.cpp
 * @author Sarah Morrison-Smith
 * @brief More advanced pointers, like a pointer to a pointer
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream> // Include input-output stream library

int main() {
    // Part 1: Basic pointer to pointer

    int a = 30;        // Declare an integer variable 'a' and initialize it to 30
    int* p = &a;       // Declare a pointer 'p' that holds the address of variable 'a'
    int** pp = &p;     // Declare a pointer to pointer 'pp' that holds the address of pointer 'p'
    
    // Output the value of 'a'
    std::cout << "Value of a: " << a << std::endl;

    // Output the value of 'p' (the address of 'a')
    std::cout << "Value of p (address of a): " << p << std::endl;

    // Output the value of 'pp' (the address of 'p')
    std::cout << "Value of pp (address of p): " << pp << std::endl;

    // Output the value pointed to by 'p' (dereferencing 'p' gives the value of 'a')
    std::cout << "Value pointed to by p: " << *p << std::endl;

    // Output the value pointed to by 'pp' (dereferencing 'pp' gives the value of 'p', which is the address of 'a')
    std::cout << "Value pointed to by pp (address of a): " << *pp << std::endl;

    // Output the value pointed to by '*pp' (dereferencing 'pp' twice gives the value of 'a')
    std::cout << "Value pointed to by *pp (value of a): " << **pp << std::endl;

    // Part 2: Dynamically allocated 2D array using pointer to a pointer

    int rows = 3, cols = 4;  // Define the number of rows and columns for the 2D array
    
    // Step 1: Create a pointer to pointer (2D array)
    int** array2D = new int*[rows];  // Allocate an array of integer pointers (each representing a row)

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        array2D[i] = new int[cols];  // For each row, allocate an array of integers (columns)
    }

    // Step 3: Populate the array with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array2D[i][j] = (i + 1 + j + 1);  // Assign values to the array, incremented based on row and column index
        }
    }

    // Step 4: Print the 2D array
    std::cout << "Dynamically allocated 2D array:" << std::endl;
    for (int i = 0; i < rows; i++) {  // Loop through each row
        for (int j = 0; j < cols; j++) {  // Loop through each column in the row
            // Output the value in the 2D array at position [i][j]
            std::cout << array2D[i][j] << " ";  // Print each element in the current row
        }
        std::cout << std::endl;  // Print a new line after each row
    }

    // Step 5: Deallocate the memory
    for (int i = 0; i < rows; i++) {
        delete[] array2D[i];  // Deallocate the memory for each row
    }
    delete[] array2D;         // Deallocate the memory for the array of pointers (the 2D array itself)

    return 0;  // Return 0 to indicate successful program execution
}
