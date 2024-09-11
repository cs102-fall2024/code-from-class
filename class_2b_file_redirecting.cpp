#include <iostream>
#include <string>

/**
 * This program calculates which cat and dog weighs the most
 * This program is an example of file I/O
 */
int main() {
    double weight;
    double max_dog = 0;
    double max_cat = 0;
    std::string animal_type;

    std::cin >> animal_type;

    while (animal_type != "end") {
       std::cin >> weight;

        if (animal_type == "dog") {
            max_dog = std::max(max_dog, weight);
        }
        else if (animal_type == "cat") {
            max_cat = std::max(max_cat, weight);
        }
        else {
            std::cout << "Unrecognized animal: " << animal_type << std::endl;
        }

        std::cin >> animal_type;
    }

    std::cout << "The largest dog weighs " << max_dog << std::endl;
    std::cout << "The largest cat weighs " << max_cat << std::endl;
}