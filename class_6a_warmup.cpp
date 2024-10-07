#include <iostream>
using namespace std;

int main() {
    int* my_int = new int; // no error here
    int* another = (int*) 20; // just no, can't do that
    my_int[1] = 10; //gross, my_int is not an array
    if (my_int[0] > 0) //not initialized
        cout << "greater than 0!" << endl; //fine by itself but won't run
    my_int = another; //memory leak
    cout << "my_int=" << *my_int << endl; //seg fault
    delete[] my_int; //bad not an array
    return 0;
}
