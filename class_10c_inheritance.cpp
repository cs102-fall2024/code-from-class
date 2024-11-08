#include<string>
#include<iostream>
using namespace std;

class Animal {
    private:
        string _name;

    public: 
        Animal(string name) {
            _name = name;
        }

        //This is a read only method because get_name() doesn't change anything
        string get_name() const {
            return _name;
        }

        //This is also a read only method because we are not changing anything, we are simply printing
        virtual void make_sound() const {
            cout << "amoebic peep" << endl;
        }
};

class Dog : public Animal {
    private:

    public:
        /**
         * @brief Construct a new Dog object, inherits the constructor from Animal
         * How does this work without a private attribute? I thought you said that we were
         * inheriting the public methods?
         * 
         * Answer: Although _name is a private member in Animal, Dog can still use methods 
         * provided by Animal (like get_name()), which can access _name internally.
         * @param name - the name of the animal
         */
        Dog(string name) : Animal(name) {}

        /**
         * @brief Overloads the make_sound method from the Animal class
         * 
         */
        void make_sound() const {
            cout << "Woof!!!" << endl;
        }

};

int main() {
    Dog goober("Goober");
    goober.make_sound();
}