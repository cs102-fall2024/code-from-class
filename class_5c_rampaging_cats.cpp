/**
 * @file class_5b_rampaging_cats.cpp
 * @author Sarah Morrison-Smith
 * @brief Using a loop to resize dynamic arrays, i.e. the cat is on a rampage
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

int main() {
    // Initial number of birds
    int numBirds = 6;
    
    // Dynamically allocate an array of birds (each bird represented by an integer)
    int* birds = new int[numBirds] {1, 2, 3, 4, 5, 6};  // Bird IDs
    
    std::cout << "Initial birds: ";
    for (int i = 0; i < numBirds; i++) {
        std::cout << birds[i] << " ";
    }
    std::cout << std::endl;
    
    // Assume that 3 birds will be eaten, we will resize the array 3 times
    for (int round = 1; round <= 3; round++) {
        std::cout << "Round " << round << ": a bird is eaten!" << std::endl;
        
        int numBirdsNew = numBirds - 1;  // New size is one less each round

        // Step 1: Dynamically allocate a new array with the smaller size
        int* newBirds = new int[numBirdsNew];
        
        // Step 2: Copy the remaining birds to the new array (skip the last bird)
        for (int i = 0; i < numBirdsNew; i++) {
            newBirds[i] = birds[i];
        }
        
        // Step 3: Delete the old array of birds
        delete[] birds;
        
        // Step 4: Point the birds pointer to the new array
        birds = newBirds;
        numBirds = numBirdsNew;  // Update the number of birds
        
        // Print the remaining birds after resizing
        std::cout << "Birds left: ";
        for (int i = 0; i < numBirds; i++) {
            std::cout << birds[i] << " ";
        }
        std::cout << std::endl;
    }

    // Cleanup: Delete the resized array to prevent memory leak
    delete[] birds;

    return 0;
}