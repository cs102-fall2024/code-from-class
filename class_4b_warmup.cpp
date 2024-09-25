/**
* Warmup for pointers, demonstrates addressing and dereferencing
* @file class_4b_warmup.pp
* @author Sarah Morrison-Smith
* @date September 25, 2024
*/

/**
 * @file class_4b_warmup.cpp
 * @author Sarah Morrison-Smith
 * @brief Warmup for pointers, demonstrates addressing and dereferencing
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int* ptr = &num;
   
    cout << &num << endl;
    cout << ptr  << endl;
    cout << num  << endl;
    cout << *ptr << endl;

    *ptr = 84;
	
    cout << num  << endl;
    cout << ptr  << endl;
	
    return 0;
}
