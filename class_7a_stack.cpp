/**
 * @file class_7a_stack.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief A simple stack class
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/* This is the maximum size of the stack, 
 *  similar to how we have a fixed/limited amount of memory
 */
const int MAX_STACK_SIZE = 1000000; 

/**
 * @brief Stack class, implements a stack using an array. Only takes ints.
 * 
 */
class Stack { 
    private:
        int _size; //Current size of the stack
        int _stack[MAX_STACK_SIZE]; //Stack represented by an array

    public:
        //Constructor. All stacks start out empty
        Stack() {
            _size = 0;
        }

        /**
         * @brief Adds an item to the top of the stack
         * 
         * @param item - the int that is added to the top of the stack
         * 
         * Exercise: make the program stop gracefully if there is an error
         */
        void push(int item) {
            assert(_size < MAX_STACK_SIZE); /// prevents stack overflow

            if(_size >= MAX_STACK_SIZE) {
                cout << "Error: Stack overflow!" << endl;
            }
            else {
                _stack[_size] = item;
                _size++;
            }
        }

        /**
         * @brief Prints the stack sideways
         * 
         * Exercise: make it print vertically like an actual stack with the
         * top on the top
         */
        void display() {
            assert(_size > 0);
            cout << "Stack[ ";
            for (int i = 0; i < _size - 1; i++) {
                cout << _stack[i] << " | ";
            }
            cout << _stack[_size -1] << " ] " << endl;
        }

        /**
         * @brief Returns what is on the top of the stack
         * 
         * @return int - what is on top of the stack
         */
        int top() {
            assert(_size > 0); //assertion for stack underflow
            return _stack[_size - 1];
        }

        /**
         * @brief Removes the top item off the stack, does not return it
         * To return, use top then pop
         * 
         * Exercise: make it exit gracefully if there's an error
         */
        void pop() {
            assert(_size > 0); // assertion for stack underflow
            if(!empty()) {
                _size--;
            }
            else {
                cout << "Error: Stack underflow!" << endl;
            }
        }

        /**
         * @brief Returns whether the stack is empty
         * 
         * @return true - stack is empty
         * @return false - stack is not empty
         */
        bool empty() {
            return _size == 0;
        }

        /**
         * @brief Returns the size of the stack i.e., how many elements are on the stack
         * 
         * @return int - the size of the stack
         */
        int size() {
            return _size;
        }
};


// Controls program flow
int main() {
    Stack important_dates;
    important_dates.push(1793);
    important_dates.push(1990);
    important_dates.push(2024);

    important_dates.display();

    //cout << important_dates.top() << endl;

    important_dates.pop();
    important_dates.display();

    cout << "is the stack empty? " <<  important_dates.empty() << endl;

    cout << "No the stack is of size " << important_dates.size() << endl;

    //Testing the assert for stack overflow
    /*for (int i = 0; i < MAX_STACK_SIZE * 2; i++) {
        important_dates.push(i);
    }*/

    for (int i = 0; i < MAX_STACK_SIZE * 2; i++) {
        important_dates.pop();
    }
}