/**
 * Class code: Storage Duration and Scope
 * 
 * @file class_3b_storage_duration_and_scope.cpp
 * @author Sarah Morrison-Smith
 * @date September 18, 2024
*/

#include <iostream>
#include <string>

using namespace std;

// Static global constant
const int LARGE_NUMBER = 1000000;

// The parameter upper_bound is automatic local
/**
 * @brief Prints powers of 2 up to a limit and returns a generated string
 * 
 * @param upper_bound - limit on how high of a power of 2 we can use
 * @return string - Generated string
 */
string some_function(int upper_bound) {

    // Automatic local variables
    int power_of_two = 1;
    string some_chars = "";

    // Static local - all function calls will use the same value!
    static char place = 'A';
    cout << place << endl;

    while ((power_of_two < upper_bound) && (power_of_two < LARGE_NUMBER)) {
        cout << power_of_two << endl;
        power_of_two *= 2;
        some_chars += place;
        place++;
    }

    cout << "All preceding powers of 2 are less than " << upper_bound << " and " << LARGE_NUMBER << endl;

    return some_chars;
}

int main() {
    // Automatic local variables
    // Note: you can use the same name as locals in some_function
    int power_of_two = 1024;
    
    cout << some_function(50) << endl;
    cout << some_function(LARGE_NUMBER) << endl;
    cout << some_function(power_of_two) << endl;
    cout << some_function(40000000) << endl;

    // Uncommenting this line will also cause an error since 'place' 
    // is not available in the main function scope.
    //cout << some_function(place) << endl;

    return 0;
}
