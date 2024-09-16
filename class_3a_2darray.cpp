/**
 * Warmup: make an array
 * 
 * @file class_3a_2darray.cpp
 * @author Sarah Morrison-Smith
 * @collaborators 102 Class - Fall 2024
 * @date September 16, 2024
*/

#include <iostream>
#include <string>

using namespace std;

// Constants for the dimensions of the Connect 4 board (6 rows, 7 columns)
const int ROWS = 6;
const int COLS = 7;

// Constants for the dimensions of a smaller board (3 rows, 3 columns)
const int ROWS_SM = 3;
const int COLS_SM = 3;

/**
 * @brief Prints the board nicely.
 * 
 * In this function, the second dimension (number of columns) of the array must be constant.
 * This is because when passing a 2D array to a function in C++, the compiler needs to know 
 * how many elements are in each row in order to calculate memory offsets and properly index 
 * the array. Without this information, the compiler cannot correctly compute where each 
 * element of the array is stored in memory.
 * 
 * The number of rows, however, can vary and is handled dynamically within the loop.
 * 
 * 
 * 
 * @param board - the 2D array that we are printing. Note that this is a constant. 
 * Using const conveys to anyone reading or maintaining the code that the function 
 * is not supposed to modify the array. It makes the function's intent clear: 
 * it only reads the array to print its contents but doesn't alter it.
 */
void print_board(const string board[][COLS]) {
    // Iterate over each row of the board
    for (int row = 0; row < ROWS; row++) {
        // Iterate over each column of the board
        for (int col = 0; col < COLS; col++) {
            // Print each element in the board with a space between elements
            cout << board[row][col] << " ";
        }
        // After each row is printed, move to the next line
        cout << endl;
    }
}

int main() {
    // A 6x7 Connect 4 board. Each element is represented as a string.
    // "." represents an empty space, "r" represents a red disc, "b" represents a blue disc.
    string connect4[ROWS][COLS] = {
        {".", ".", ".", ".", ".", "b", "."},
        {".", ".", ".", ".", ".", "r", "."},
        {"r", ".", ".", ".", ".", "b", "."},
        {"b", ".", ".", ".", ".", "r", "."},
        {"r", "b", ".", "r", ".", "b", "."},
        {"r", "r", "b", "r", ".", "b", "b"}
    };

    // A smaller 3x3 array for testing purposes (currently initialized as empty strings)
    string new_array[ROWS_SM][COLS_SM] = {""};

    // Print the Connect 4 board
    // The print_board function works because the second dimension (COLS) is constant (7),
    // which allows the compiler to correctly compute memory addresses for each element.
    print_board(connect4);

    // We can't print `new_array` with `print_board` as written because its second dimension
    // (COLS_SM = 3) is different from the Connect 4 board's second dimension (COLS = 7).
    // If we tried to pass `new_array` to `print_board`, the compiler would complain because
    // the function expects arrays with 7 columns, not 3.
    // Uncommenting the next line would cause a compile error:
    // print_board(new_array);

    // Accessing elements of the array:
    // Here's an example of indexing a specific element of the Connect 4 board.
    // We can access the 5th row, 3rd column like this:
    cout << "connect4[4][2]: " << connect4[4][2] << endl;  // Output: "."

    return 0;
}
