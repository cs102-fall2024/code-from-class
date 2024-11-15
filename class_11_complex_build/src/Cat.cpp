#include "Cat.h"
#include <iostream>
using namespace std;

//Cat(const string& name);
Cat::Cat(const string& name){
    _name = name;
}
//void meow() const;
void Cat::meow() const {
    cout << _name << " says Meow!!" << endl;
}

//void purr() const;
void Cat::purr() const {
    cout << _name << " is purring happily!" << endl;
}