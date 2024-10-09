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
 * @brief This is a class for representing playing cards
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

            if(_rank.size() > 2) // if the rank is a face card or an Ace
                result += _rank[0];
            else
                result += _rank;

            return result;
        }

        string short_string2() {
            string result = "";

            result += _suit[0];

            if(_rank == "10") // if the rank is a face card or an Ace
                result += _rank;
            else
                result += _rank[0];

            return result;
        }

        /**
         * @brief Returns true if the card is a face card
         * 
         * @return true - The card is a face card
         * @return false - The card is not a face card
         */
        bool is_face() {
            // Return true if the rank is Jack, Queen, or King
            return _rank == "Jack" || _rank == "Queen" || _rank == "King";
        }

        /**
         * @brief Returns an integer representation of the card rank
         * Ace is 14, King is 13, Queen is 12, Jack is 11, numeric cards return their value.
         * 
         * @return int - the numeric representation of the card's rank
         */
        int rank_number() {
            if (_rank == "Ace") 
                return 14;
            else if (_rank == "King")
                return 13;
            else if (_rank == "Queen")
                return 12;
            else if (_rank == "Jack")
                return 11;
            else if (_rank == "10")
                return 10;
            
            // How can we stop from making a million if statements?
            // We could use a lookup table (e.g., a map) to associate ranks with numbers.
            // For non-face cards (e.g., 2-9), subtracting the ASCII value of '0' from the character
            // gives us the numeric value.
            return _rank[0] - '0'; // This converts the char '2' to the integer 2, etc.

        }

        /**
         * @brief Returns true if this card has equal rank to another card
         * 
         * @param other Reference to the card we are comparing to
         * @return true - same rank
         * @return false - different rank
         */
        // We can use a reference here so we don't have to copy the entire object! This is common when using objects unless you NEED a copy.
        // When would you need a copy?
        // You'd need a copy if you want to make changes to an object without affecting the original object.
        bool equal_rank (Card &other) { 
            return rank_number() == other.rank_number();
            // Wait what? We don't have to pass two cards in? How does this work?
            // Because these are methods, not functions. The method is called on one Card object 
            // and the other is passed as an argument. So, there's an implicit "this" pointer involved.
        }

        /**
         * @brief Returns true if this card has a higher rank than the other card
         * 
         * @param other Reference to the card we are comparing to
         * @return true - this card has a higher rank
         * @return false - this card does not have a higher rank
         */
        bool higher_rank (Card &other) {
            return rank_number() > other.rank_number();
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

    cout << a_card.short_string2() << endl;
    cout << l_card.short_string2() << endl;
    cout << s_card.short_string2() << endl;
}