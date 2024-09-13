#include <iostream>

int main() {
    std::cout << "Get ready" << std::endl;
    for (int i = 0; i < 1000; i++) {
        std::cout << i << " ";
    }

    for (int j = 0; j < 2000000000; j++) {
        // busy wait
    }

    std::cout << "\n";
    return 0;
}
