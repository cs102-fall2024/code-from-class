#include <iostream>
using namespace std;

/**
 * @brief Runs the program
 * 
 * @return int - whether the program exited well
 */
int main() {
    /**
     * @brief This loop illustrates O(n^2) behavior
     * 
     */
    for (int i = 0; i < 5; i ++) {
        cout << "iteration : " << i << endl;
        for (int j = 0; j < 5; j++) {
            cout << j << endl;
        }
    }

}