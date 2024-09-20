/**
 * Class code: Local Variables and Scope
 * 
 * @file class_3b_local_vars.cpp
 * @author Sarah Morrison-Smith
 * @date September 18, 2024
*/

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Function to print details about a cat a certain number of times
 * 
 * @param num_times local variable to this function
 * @return string the cat's name after the program
 */
string print_stuff(int num_times) {
    // This 'cat' variable is local to the function 'print_stuff'
    // It is distinct from any 'cat' variables declared in other functions like main.
    // Due to local scope, variables with the same name in different scopes do not interfere with each other.
    string cat = "Mila"; // Local string variable initialized with the value "Mila"

    // This for loop runs 'num_times' iterations.
    // The variable 'i' is local to the loop block and will be destroyed after the loop ends.
    for (int i = 0; i < num_times; i++) {
        // Prints the value of the string 'cat' at the start of each loop iteration.
        // Initially, it will always print "Mila" since this is the value of the 'cat' variable declared at the function level.
        cout << "Cat's name at the start of the loop: " << cat << endl;

        /**
         * This is a new 'cat' variable, local only to the loop body.
         * It is an integer, which is different from the string 'cat' declared earlier.
         * Even though it shares the same name, the two 'cat' variables exist in different scopes.
         * The integer 'cat' only exists inside each iteration of the loop.
         */
        int cat = 15; // Local integer variable named 'cat', only valid within the loop body.
        
        // Prints the integer value '15' since this refers to the 'cat' declared inside the loop.
        cout << "Cat's name at the end of the loop: " << cat << endl;

        // After the loop iteration ends, this integer 'cat' variable goes out of scope,
        // and the string 'cat' from the function scope will be used again.
    }

    // The variable 'i' was declared inside the loop, so it is not accessible outside the loop.
    // Uncommenting the following line would cause a compilation error because 'i' is out of scope.
    // cout << "i isn't available here, see: " << i << endl;

    // Trying to redeclare 'cat' here as a different type (e.g., double) would also cause a compilation error
    // because 'cat' is already declared in this scope as a string.
    // Uncommenting the following line would result in an error:
    // double cat = 2.5;

    // Returns the value of the string 'cat' declared at the function scope, which is "Mila".
    return cat;
}

int main() {
    // This 'cat' variable is local to the main function. It is an integer.
    // It is completely separate from the 'cat' variable declared in 'print_stuff'.
    int cat = 5;

    // Call 'print_stuff' with 'cat' as the argument, which is 5.
    // This means the loop in 'print_stuff' will run 5 times.
    string name = print_stuff(cat); // 'cat' here is passed by value, so only the value (5) is passed, not the variable itself.

    // After 'print_stuff' finishes, 'name' will hold the value returned by the function,
    // which is the string "Mila".
    cout << "The cat's name was " << name << endl; // Prints "The cat's name was Mila"
}
