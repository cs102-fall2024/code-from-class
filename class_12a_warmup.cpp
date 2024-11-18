#include<iostream>
using namespace std;

int tri_number(int n){
    if (n==1)
        return 1;
    return n + tri_number(n-1);
}

int main() {
    int n;
    cout << "Enter a positive integer to find its triangular number: ";
    cin >> n;

    int result = tri_number(n);
    cout << "The " << n;
    cout << "th triangular number is: " << result << endl;
    

    return 0;
}
