#include <iostream>

bool is_lowercase(char letter){
    return letter >= 'a' && letter <= 'z';
}

/**
 * Only capitalize ch if the character is lowercase
 * Otherwise return
 */


int main() {
    char input_char = ' ';
    std::cout << "Enter a letter: ";
    std::cin >> input_char;
    std::cout << "The letter is";
    if (!is_lowercase (input_char)){
        std::cout << " not";
    }
    std::cout << " lowercase" << std::endl << std::endl;
    std::cout << input_char << " in ASCII is " << (int)input_char << std::endl;

    //std::cout << input_char << std::endl;
}