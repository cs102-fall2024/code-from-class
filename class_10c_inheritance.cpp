#include<string>
#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Basic animal class, super class for Cats and Dogs
 * 
 */
class Animal {
    //private: // makes it so that only the Animal class has access to name
    protected: // allows subclasses to access name
        string _name;

    public: 
        /**
         * @brief Construct a new Animal object
         * 
         * @param name - name of the animal
         */
        Animal(string name) {
            _name = name;
        }

        /**
         * @brief Get the name attribute of the animal
         * Note: This is a read only method because get_name() doesn't change anything
         * @return string - name
         */
        string get_name() const {
            return _name;
        }

        /**
         * @brief The animal makes a sound
         * 
         * This is also a read only method because we are not changing anything, we are simply printing
         */
        virtual void make_sound() const {
            cout << "amoebic peep" << endl;
        }
};

/**
 * @brief Dog class. Subclass of Animal class
 * Note: ": public Animal" makes it so that Dog inherits all the public methods from the Animal class
 */
class Dog : public Animal {
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
         * Dogs woof!
         */
        void make_sound() const {
            cout << "Woof!!!" << endl;
        }

};

/**
 * @brief Cat class, inherits from Animal superclass
 */
class Cat : public Animal {
private:
    string _collar_color;

public: 
    /**
     * @brief Construct a new Cat object, inherits the name part from the animal class
     * adds the collar_color part
     * @param name - name of the cat
     * @param collar_color - color of the cat's collar
     */
    Cat(string name, string collar_color) : Animal(name) {
        _collar_color = collar_color;
    }

    /**
     * @brief Overwrites the make sound
     * 
     */
    void make_sound() const {
        //cout << "Meow!" << " my name is " << get_name();
        cout << "Meow!" << " my name is " << _name;
        cout << " and my collar color is " << _collar_color << endl;
    }
};

// Runs everything
int main() {
    Dog goober("Goober");
    //goober.make_sound();

    Cat mila("Mila", "pink");
    Cat frankie("Frankie", "teal");

    //mila.make_sound();
    //frankie.make_sound();

    //Animal m = mila;
    //cout << m.get_name() << endl;
    //m.make_sound();
    /*Animal* mila_ptr = &mila;
    mila_ptr->make_sound();*/

    /*vector<Animal> pets;
    pets.push_back(mila);
    pets.push_back(frankie);
    pets.push_back(goober);

    for (int i = 0; i < 3; i++) {
        Animal pet = pets[i];
        //cout << pet.get_name() << endl;
        pet.make_sound();
    }*/

   /*vector<Animal*> pets_ptrs;
   pets_ptrs.push_back(&mila);
   pets_ptrs.push_back(&frankie);
   pets_ptrs.push_back(&goober);

   for (int i = 0; i < 3; i++) {
        Animal* pet = pets_ptrs[i];
        //cout << pet.get_name() << endl;
        pet->make_sound();
    }*/

   mila.make_sound();

   //Doesn't work because _name is protected! You can access it from the subclasses and superclass
   //but not from outside the class!
   //cout << mila._name << endl;
    
}