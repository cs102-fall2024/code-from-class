#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

int main() {
    int my_array[ROWS][COLS] = {{0,1,2},
                                {3,4,5},
                                {6,7,8}};

    cout << my_array[0][4] << endl;
    cout << my_array[2][4] << endl;

}