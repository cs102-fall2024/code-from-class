#include <string>
#include <iostream>

/*int main() {
    std::string words = "Hello World!";
    char letter = words[6]; //W
    words.size(); //12
}*/

/*int main() {

    int cats;
    double meters;

    //std::cout << "How many cats do you have? ";
    //std::cin >> cats;
    //std::cout << typeid(cats).name() << std::endl;
    // do it with meters

    std::string my_input;
    std::cout << "Enter a whole line of input: ";
    std::getline(std::cin, my_input);
    std::cout << "You entered: " << my_input << std::endl;

    return 0;
}*/

int main() {
    std::string input;
    char ch;

    std::cout << "Enter a string: ";
    //std::cin >> input;
    std::getline(std::cin, input);
    std::cout << input << std::endl;

    for (int i = 0; i < input.size(); i++) {
        ch = input[i];
        std::cout << "The ASCII value of " << ch << " is " << int(ch) << std::endl;
    }
}