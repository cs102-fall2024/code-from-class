#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

int main() {
    int empty_array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++){
        empty_array[i] = 42;
        cout << "empty_array[" << i << "] =" << empty_array[i] << endl;
    }

    //cout << empty_array[ARRAY_SIZE+15] << endl;
    //cout << empty_array[ARRAY_SIZE+5000] << endl;

    cout << empty_array << endl;
}