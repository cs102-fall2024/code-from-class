/**
 * @file class_14a_dollar.cpp
 * @author Sarah Morrison-Smith
 * @brief Basic USD class for operator overloading
 * @version 0.1
 * @date 2024-12-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

class Dollars {
private:
    int _dollars;
    int _cents;

public:
    Dollars(int, int);
    Dollars operator+(const Dollars& other);
    Dollars operator*(const int& factor);
    int get_dollars() const {return _dollars;}
    int get_cents() const {return _cents;}
};

Dollars::Dollars(int dollars, int cents) {
    _dollars = dollars;
    _cents = cents;
}

//BAD Why? Because cents could be over 100 and therefore really secretly be a dollar
/*Dollars Dollars::operator+(const Dollars& other) {
    int dollars = _dollars + other._dollars;
    int cents = _cents + other._cents;
    return Dollars(dollars, cents);
}*/

Dollars Dollars::operator+(const Dollars& other) {
    int cents = _cents + other._cents;
    int dollars = _dollars + other._dollars + (cents/100);
    return Dollars(dollars, cents % 100);
}

Dollars Dollars::operator*(const int& factor) {
    int cents = _cents * factor % 100;
    int dollars = (_dollars * factor) + ((_cents * factor)/100);
    return Dollars(dollars, cents);
}

ostream& operator<<(ostream& out, const Dollars& d) {
    out << "$" << d.get_dollars() << ".";
    //handle formatting for < 10 cents
    if(d.get_cents() < 10)
        out << 0;
    out << d.get_cents();

    return out;
}

int main() {
    Dollars change(7, 53);
    Dollars a_bit_more(8, 6);
    Dollars should_wrap (0, 80);

    /*Dollars money = change + a_bit_more;

    cout << money.get_dollars() << " dollars and " << money.get_cents() << " cents" << endl;

    Dollars new_money = money + should_wrap + a_bit_more;

    cout << new_money.get_dollars() << " dollars and " << new_money.get_cents() << " cents" << endl;*/

    Dollars money = change * 10;
    //money += a_bit_more; Exercise: write this operator!

    //cout << money.get_dollars() << " dollars and " << money.get_cents() << " cents" << endl;

    cout << change << " * 10 = " << money << endl;
}