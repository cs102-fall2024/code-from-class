#include <iostream>

    int digit_sum(int n) {
        if (n == 0)
            return 0;
        return (n % 10) + digit_sum(n / 10);
    }

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "The sum of the digits of " << number << " is " << digit_sum(number) << std::endl;

    return 0;
}
