/**
 * Warmup: make an array
 * 
 * @file warmup.cpp
 * @author Sarah Morrison-Smith
 * @collaborators 102 Class - Fall 2024
 * @date September 16, 2024
*/
#include <iostream>
#include <string>

using namespace std;


int main() {
    // make an array containing room for 6 ints
    // with only the first 3 ints initialized
    // those ints should be initialized to 1, 2, 3

    //this bit of code initializes the first 3 elements
    //the side effect is that the rest of the elements are default values
    //int my_array[6] = {1,2,3};

    int my_array[6];
    //char my_array[6] = {'a'};
    my_array[0] = 1;
    my_array[1] = 2;
    my_array[2] = 3;
    for (int i = 0; i < 6; i++){
        cout << my_array[i] << endl;
    }
    
    return 0;
}