/**
 * @file class_10a_warmup.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief Recursion practice!
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
using namespace std;

/**
 * @brief Recursive factorial function
 * 
 * @param n - the number to take the factorial of
 * @return int - the factorial of the number n
 */
int factorial(int n) {
    if(n <= 1)
        return 1;
    return n*factorial(n-1);
}


int main() {
    int number;
    cin >> number;
    cout << factorial(number) << endl;
    return 0;
}
