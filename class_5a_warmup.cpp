#include <iostream>
using namespace std;

// Function to dynamically create an array of a given size
void create_array(int*& arr, int size) {
    arr = new int[size];  // Dynamically allocate memory for the array
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;  // Initialize the array with values 1, 2, 3, ...
   }
}

// Function to modify the array (e.g., multiply all elements by 2)
void modify_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Multiply each element by 2
    
    }

}

// Function to print the array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    
    }
    cout << endl;

}

int main() {
    int* my_array = nullptr;  // Pointer to the array
    int size = 5;            // Size of the array

    // Create the array
    create_array(my_array, size);

    // Modify the array
    modify_array(my_array, size);

    // Print the array after modification
    print_array(my_array, size);
    delete[] my_array;
    return 0;
}