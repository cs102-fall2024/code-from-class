/**
 * @file class_5c_2D_array.cpp
 * @author Sarah Morrison-Smith
 * @brief Let's do 2D Dynamic Arrays
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

const int NUM_ROWS = 3, NUM_COLS = 4; //rows and columns

int main() {

    int** arr = new int*[NUM_ROWS]; // array of pointers

    for (int i = 0; i < NUM_ROWS; i++) {
        arr[i] = new int[NUM_COLS]; //allocating memory for array of size NUM_COLS at each row
    }

    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++){
            arr[row][col] = row + col; //arbitrary values
        }
    }

    cout << "Array acess with arr[row][col] notation" << endl;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Accessing elements using pointers" << endl;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++){
            //arr[row][col] equivalent to *(*(arr + row) + col)
            //cout << *(*(arr + row)) << " ";
            
            cout << *(*(arr + row) + col ) << " ";
        }
        cout << endl;
    }
    
    //THESE ARE THE SAME for getting the address
    cout << &arr[1][2] << endl;
    cout << (*(arr + 1) + 2) << endl;

    //Dereferencing to modify elements
    *(*(arr + 1) + 2) = 100;
    cout << arr[1][2] << endl;

    // DELETE
    for (int row = 0; row < NUM_ROWS; row ++) {
        delete[] arr[row]; //delete each row
    }
    delete[] arr; // then we delete the array
}