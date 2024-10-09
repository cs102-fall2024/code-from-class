/**
 * A Bubble class
 * @file warmup.cpp
 * @author Sarah Morrison-Smith
 * @collaborators Darren Strash
 * @date October 9, 2024
 */
#include <iostream>

using namespace std;

class Bubble {
    private:
        double _diameter;
        double _max_diameter;

    public:

        Bubble(double diameter, double max_diameter) {
            _diameter = diameter;
            _max_diameter = max_diameter;

        }

        bool popped() {
            return _diameter > _max_diameter;
        }

        // The same thing, not as good style
        /*bool popped() {
            if (_diameter > _max_diameter) {
                return true;
            }
            else {
                return false;
            }
        }*/

        void double_diameter() {
            //_diameter = _diameter * 2;
            _diameter *= 2; //arguably better style
        }

        double get_diameter () {
            return _diameter;
        }

};

// Make a class that supports the following code
int main() {
    double max_diameter = 10;
    double diameter = 1;
    Bubble bubble = Bubble(diameter, max_diameter);
    while (!bubble.popped()) {
        bubble.double_diameter();
        cout << "Bubble popped? " << bubble.popped() << endl;
        cout << "current diameter is " << bubble.get_diameter() << endl;
    }
    std::cout << "The bubble popped!" << std::endl;
    return 0;
}
