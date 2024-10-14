#include <iostream>
using namespace std;

class Cat {
private:
    string _name;

public:
    Cat(string name) {
        _name = name;
    }

    void meow() {
        cout << _name << " says Meow! " << endl;
    }
};

int main() {
    Cat mila("Mila");
    mila.meow();
    return 0;
}