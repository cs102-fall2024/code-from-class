#include <iostream>
#include <string>
using namespace std;


const int SIZE = 10;

int main() {
    int my_array[10] = {1,2,3,4,5,6,7,8,9,10};

    int* array_pointer = my_array;

    cout << array_pointer[3] << endl;

    //cout << *array_pointer[3] << endl; //does not compile

    string my_string_array[3] = {"cats", "birds", "possums"};
    string* string_array_pointer = my_string_array;

    //cout << *string_array_pointer[2] << endl;


}