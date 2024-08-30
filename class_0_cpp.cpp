#include <iostream>
#include <string>

//this is my comment
int main() {
  std::string my_string = "Hello 102 Class!";
  std::string reversed_string = "";

  for (char c : my_string){
    reversed_string = c + reversed_string;
  }

  std::cout << reversed_string;
  std::cout << std::endl;

  return 0;
}

// To run, execute the following commands:
// g++ class_0_cpp.cpp -o myprogram
// ./myprogram