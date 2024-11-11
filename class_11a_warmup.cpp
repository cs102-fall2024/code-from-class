#include<iostream>
using namespace std;

double power(double base, int exponent) {
    if (exponent == 0)
        return 1;
    
    if (exponent < 0){
        return 1 / power(base, -exponent);
    }

    return base * power(base, exponent - 1);

}

int main() {
    double x = 2.0;
    int n = 3;
    cout << x << " raised to the power of " << n << " is " << power(x,n) << endl;
    
}