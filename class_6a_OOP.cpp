/**
 * @file class_6a_OOP.cpp
 * @author Sarah Morrison-Smith
 * @brief Our first class!
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
using namespace std;


/**
 * @brief This isa class for representing playing cards
 * Ranks are stored as strings, such as "3", "10", "Queen"
 * 
 * This is the class delcaration
 */
class Card {
    private: //only accessible within the class
        // Attributes
        string _suit; //stores suit of the card ("Hearts", "Spades")
        string _rank; //stores the rank of the card ("2", "Jack")

    public: //accessible outside the class
        //methods

        //constructor
        Card(string suit, string rank) {
            _suit = suit;
            _rank = rank;
        }

        Card(string suit){
            _suit = suit;
            _rank = "Ace";
        }

        Card(){
            _suit = "Spades";
            _rank = "Queen";
        }

        // Getter methods get the values of the attributes of the class
        string get_suit() {
            return _suit;
        }

        string get_rank() {
            return _rank;
        }

        // Setter methods change the calues of the attributes of the class
        void set_suit(string new_suit) {
            _suit = new_suit;
        }

        void set_rank(string new_rank) {
            _rank = new_rank;
        }

        //Other methods
        string long_string() {
            string result = _rank + " of " + _suit;
            return result;
        }

        string short_string() {
            string result = "";

            result += _suit[0];

            

            return result;
        }


};

int main() {
    Card l_card = Card("Hearts", "Jack");
    Card a_card = Card("Spades", "3");
    Card s_card = Card("Diamonds", "Ace");

    Card test_card = Card("Hearts");

    Card* my_array = new Card[3];
    
    Card card_array[3] = {l_card,a_card,s_card};

    cout << a_card.long_string() << endl;
    cout << l_card.long_string() << endl;
    cout << s_card.long_string() << endl;
}