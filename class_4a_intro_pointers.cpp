/**
 * @file class_4a_intro_pointers.cpp
 * @author Sarah Morrison-Smith
 * @brief 
 * @version 0.1
 * @date 2024-09-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int main() {

    int benny = 2;
    int* benny_ptr = &benny;

    int frankie = 5;
    int* frankie_ptr = &frankie;

    //string mila = "Mila";
    //string* mila_ptr = &mila;

    benny_ptr = &frankie;

    /*cout << "Benny is " << benny << " years old " << endl;
    cout << "benny is stored at " << &benny << " memory location " << endl;
    cout << "this is the same as " << benny_ptr << endl; 

    cout << "Frankie is " << frankie << " years old " << endl;
    cout << "frankie is stored at " << &frankie << " memory location " << endl;
    cout << "this is the same as " << frankie_ptr << endl; */

    /*cout << "Mila is called " << mila << endl;
    cout << "mila is stored at " << &mila << " memory location " << endl;
    cout << "this is the same as " << mila_ptr << endl; */

    int array[7] = {4, 29, 3, 4, 5, 6, 9};
    //cout << array << endl;
    int* what = array;
    cout << &array << endl;
    cout << *array << endl;

}