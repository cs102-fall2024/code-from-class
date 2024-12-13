#include <iostream>
#include <string>
using namespace std;

template <typename T>
T find_min(T a, T b) {
    return (a < b) ? a : b;
}

template<> /// what does this <> mean? Indicates specialiazation
double find_min<double> (double a, double b) {
    return (abs(a) < abs (b)) ? a : b;
}

template<>
string find_min<string> (string a, string b) {
    return(sizeof(a) < sizeof(b)) ? a : b;
}

int main() {
    cout << "Min of 5 and -10 " << find_min(5, -10) << endl;
    cout << "Min of -3.14 and 2.71 by absolute value " << find_min(-3.14,2.71) << endl;
    cout << "Min of Frankie and Mila " << find_min("Frankie", "Mila") << endl;
}

