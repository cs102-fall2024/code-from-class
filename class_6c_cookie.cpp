/**
 * @file class_6b_cookie.cpp
 * @author Sarah Morrison-Smith & CS 102 Class
 * @brief A simple cookie class
 * @version 0.1
 * @date 2024-10-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 
 * 
 */
class Cookie {

// Attributes
    private:
    //int _how_much_flour;
    bool _has_flour;
    //int _bites_taken;
    float _amount_left;
    string _status;
    string _flavor;
    int _size;


// Methods
    public:
    Cookie(bool gluten, string flavor, int size) {
        _has_flour = gluten;
        _flavor = flavor;
        _size = size;
        _amount_left = 1;
        _status = "unbaked";
    }

    string get_status(){
        return _status;
    }

    void bake_cookie() {
        if (_status == "unbaked") {
            _status = "baking";
            cout << "Your cookie is baking" << endl;
        }
        else if (_status == "baking") {
            _status = "baked";
            cout << "Yum! Your cookie is ready!" << endl;
        }
        else {
            _status = "burned";
            cout << "Oops, you burned that cookie!" << endl;
        }
    }

    void take_bite() {
        if (_status == "baked" && _amount_left >= 0.25) {
            _amount_left -= 0.25;
            cout << "Yum! You ate a quarter of a cookie" << endl;
        }
        else {
            cout << "You can't eat that!" << endl;
        }
    }


};

// Runs the program
int main() {
    Cookie gf_chocolate_chip(false, "chocolate chip", 48);
    gf_chocolate_chip.bake_cookie();
    gf_chocolate_chip.bake_cookie();
    cout << "Has our cookie baked? The status is: " << gf_chocolate_chip.get_status() << endl;

    for(int i = 0; i < 4; i++){
        gf_chocolate_chip.take_bite();
    }

}