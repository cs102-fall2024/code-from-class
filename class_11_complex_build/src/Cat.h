#ifndef CAT_H
#define CAT_H

#include<string>
using namespace std;

class Cat {
    public:
        Cat(const string& name); // the reference part avoids copying,
        // and the const prevents us from changing the name in the constructor
        void meow() const;
        void purr() const;

    private:
        string _name;
};

#endif