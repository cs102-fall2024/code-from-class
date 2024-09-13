#include <iostream>
#include <string>

int main() {
    std::string mystery_var = " ";
    std::cout << "What is your name?:";
    std::cin >> mystery_var;
    std::cout << std::endl << mystery_var <<std::endl;
    return 0;
}