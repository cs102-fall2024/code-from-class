/**
 * @file class_5a_vectors.cpp
 * @author Sarah Morrison-Smith
 * @brief Playing with vectors!
 * @version 0.1
 * @date 2024-09-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;

    //add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    //access and modify elements
    numbers[0] = 100; //modifies the first element, looks like an array?

    //iterate through vector
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}