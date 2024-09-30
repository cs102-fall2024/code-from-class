/**
 * @file class_5a_passing.cpp
 * @author Sarah Morrison-Smith
 * @brief This program uses hungry cats to demonstrate pass by reference vs pass by value
 * @version 0.1
 * @date 2024-09-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>

using namespace std;
/**
 * @brief Function that takes an argument by value (makes a copy)
 * 
 * @param cat The cat we are feeding
 */
void feed_by_value(string cat) {
    cat = "full"; // Changing the local copy of the cat's status
    cout << "Inside feed_by_value: The cat is now " << cat << endl;
}

/**
 * @brief Function that takes an argument by reference (modifies the original variable)
 * 
 * @param cat 
 */
void feed_by_reference(string &cat) {
    cat = "full"; // Changing the original cat's status
    cout << "Inside feed_by_reference: The cat is now " << cat << endl;
}

//Runs the program
int main() {
    // Regular variable
    string cat_status = "hungry";

    // Reference variable (alias for cat_status)
    string &ref_cat_status = cat_status;

    cout << "Before feeding: The cat is " << cat_status << endl;

    // Passing the cat_status by value (copy)
    //feed_by_value(cat_status);
    //cout << "After feed_by_value: The cat is still " << cat_status << endl;
    //Will this change the status? Why or why not?

    // Passing the cat_status by reference (original is modified)
    //feed_by_reference(cat_status);
    //cout << "After feed_by_reference: The cat is now " << cat_status << endl;
    //Will this change the status? Why or why not?

    // Showing the reference variable is linked to the original variable
    ref_cat_status = "sleepy"; // Changing through the reference variable
    cout << "After modifying via ref_cat_status: The cat is now " << cat_status << endl;
    //this demostrates that the reference variable affects the original

    return 0;
}
