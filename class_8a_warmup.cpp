/**
 * @file class_8a_warmup.cpp
 * @author Sarah Morrison-Smith
 * @brief Warmup for Asserts
 * @version 0.1
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/**
 * @brief Returns whether a word is a palindrome or not
 * 
 * @param input_string - the word to check
 * @return true - it is a palindrome
 * @return false - it is not a palindrome
 */
bool is_palindrome(const string& input_string) {
    string reversed_string = input_string;
    reverse(reversed_string.begin(), reversed_string.end());
    return input_string == reversed_string;
}

int main() {
    string word_to_check;
    cout << "Enter a word: "; 
    cin >> word_to_check;
    //assert(is_palindrome(word_to_check));
    if(is_palindrome(word_to_check))
        cout << word_to_check << " is a palindrome! " << endl;
    else
        cout << word_to_check << " is NOT a palindrome! " << endl;
}

