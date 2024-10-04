/**
 * @file class_5b_cat_and_bird.cpp
 * @author Sarah Morrison-Smith
 * @brief Example of resizing a dynamically allocated array using cats and birds
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

int main() {
    // Initial number of birds
    int numBirds = 5;
    
    // Dynamically allocate an array of birds (each bird represented by an integer)
    int* birds = new int[numBirds] {1, 2, 3, 4, 5};  // Bird IDs
    
    std::cout << "Initial birds: ";
    for (int i = 0; i < numBirds; i++) {
        std::cout << birds[i] << " ";
    }
    std::cout << std::endl;
    
    // One bird gets eaten by a cat, so we need to resize the array to 4 birds
    int numBirdsNew = numBirds - 1;
    
    // Step 1: Dynamically allocate new array with one less bird
    int* newBirds = new int[numBirdsNew];
    
    // Step 2: Copy the existing birds to the new array (except the last one)
    for (int i = 0; i < numBirdsNew; i++) {
        newBirds[i] = birds[i];
    }
    

    // Step 3: Delete the old array of birds
    delete[] birds;

    // Step 4: Point the birds pointer to the new array
    birds = newBirds;
    
    std::cout << "Birds after resizing (one eaten by a cat): ";
    for (int i = 0; i < numBirdsNew; i++) {
        std::cout << birds[i] << " ";
    }
    std::cout << std::endl;
    
    // Cleanup: Delete the resized array to prevent memory leak
    //delete[] birds;

    return 0;
}
