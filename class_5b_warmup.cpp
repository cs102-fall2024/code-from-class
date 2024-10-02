/**
 * @file class_5b_warmup.cpp
 * @author Sarah Morrison-Smith
 * @brief Class 5b Warmup!
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>

using namespace std;

// Finish the program so that the program reads `size'
// ints from the user and puts them in an array. Your program
// should be free from memory errors.
int main() {
    int size = 0;
    cout << "Gimme a size! ";
    cin >> size;

    int* times = new int[size];

    for (int index = 0; index < size; index++) {
       // times[index] = index;
       //times[index] = 7;
       cin >> times[index];
       cout << "you entered: " << times[index] << endl;
    }
    cout << endl;

    for (int i = 0; i < size; i ++){
        cout << times[i] << " ";
    }
    cout << endl;

    delete[] times;

    return 0;
}
