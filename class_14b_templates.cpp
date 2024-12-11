#include <iostream>
using namespace std;

template <typename T>
void swap_values(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T find_max(T a, T b){
    return ( a > b ) ? a : b;
}

int main() {
    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap_values(x,y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    double a=1.1, b=2.2;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap_values(a,b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    cout << "Max of 3 and 7: " << find_max(3,7) << endl;
    cout << "Max of 3.5 and 7.5: " << find_max(3.5,7.5) << endl;
    cout << "Max of Mila and Frankie: " << find_max("Frankie", "Mila") << endl;



    return 0;
}