#include <iostream>
using namespace std;

void function1() {
    int static num = 0; 
    num = 2;
    num++;
    cout << "Inside function1, static num = " << num << endl;
}

void function2() {
    int static num = 100;  
    num += 10;
    cout << "Inside function2, static num = " << num << endl;
}

int main() {
    int num = 500;
    cout << "Inside main, num = " << num << endl;

    function1();
    function2();

    function1();
    function2();

    return 0;
}