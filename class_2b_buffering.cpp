#include <iostream>
#include <chrono>
#include <thread>

int main() {
    //int number;
    //std::cout << "Enter a number: ";
    // Now flush the output buffer so that the above text is immediately printed
    //std::cout.flush();
    //std::cin >> number;
    // Demonstrating output buffer
    //std::this_thread::sleep_for(std::chrono::seconds(3)); // Waits for 3 seconds
    //std::cout << std::endl << "This message appears immediately if buffering is off." << std::endl;

   
    

    // Demonstrating input buffer
    int number = 0;
    std::cin >> number; // Input a number from the user
    std::cout << "You entered: " << number << std::endl;

    return 0;
}