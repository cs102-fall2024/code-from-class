#include<iostream>
using namespace std;

int count_ways(int n) {
    if (n == 0) 
        return 1;
    else if (n < 0) {
        return 0;
    }

    return count_ways(n-1) + count_ways(n-2);
}

int main() {
    int n;
    // Input number of steps
    cout << "Enter the number of steps: ";
    cin >> n;

    // Display the result
    cout << "There are " << count_ways(n);
    cout << " ways to reach the top of a staircase with ";
    cout << n << " steps." << endl;

    return 0;
}
