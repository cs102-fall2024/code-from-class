/**
 * @file class_8a_dynamic_stack.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief Dynamically allocated stack
 * @version 0.1
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/**
 * @brief Stack implemented with dynamic array
 * 
 */
class DynamicStack {
private:
    int _capacity; //capacity of the stack
    int _size; //current size of the stack
    int* _stack; //dynamically allocated stack

public:
    /**
     * @brief Construct a new Dynamic Stack object
     * Note: default constructor has no parameters
     */
    DynamicStack() {
        _size = 0; //all stacks start off empty
        _capacity = 1; //by default, all stacks only hold one element
        _stack = new int[_capacity]; //dynamically allocate the array
    }

    /**
     * @brief Construct a new Dynamic Stack object
     * Note: Not a default constructor, it specifies the initial capacity
     * @param initial_capacity - the capacity we want the stack to have when we create it
     */
    DynamicStack(int initial_capacity) {
        _size = 0; //all stacks start off empty
        _capacity = initial_capacity; //we can specify the capacity
        _stack = new int[_capacity]; //and the dynamically allocate the stack
    }

    /**
     * @brief Destroy the Dynamic Stack object
     * Note: destructor, indicated by the ~ symbol going to be automatically called
     */
    ~DynamicStack() {
        delete[] _stack;
    }

    /**
     * @brief Get the capacity attribute
     * 
     * @return int - the capacity of the stack
     */
    int get_capacity() {
        return _capacity;
    }
    
    /**
     * @brief Get the size attribute
     * 
     * @return int - the size of the stack
     */
    int get_size() {
        return _size;
    }

    /**
     * @brief Push a new int x to the top of the stack
     * 
     * @param x - the int to be put on the top of the stack
     */
    void push(int x){
        if(_size == _capacity){
            resize();
        }
        _stack[_size] = x;
        _size++;
    }

    /**
     * @brief Resizes the stack if we ran out of space
     * 
     */
    void resize(){
        //copy of our stack for preserving the stack contents
        int* temp = _stack; // creating a copy not a reference

        //increase our capacity and make a new array
        _capacity++;
        _stack = new int[_capacity];

        for (int i = 0; i < _size; i++) {
            _stack[i] = temp[i];
        }

        //delete temp
        delete[] temp;
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

int main() {
    DynamicStack test_stack(3);
    test_stack.push(1);
    test_stack.push(2);
    test_stack.push(3);
    test_stack.display();
    cout << "our test stack has a size of " << test_stack.get_size() << endl;
    cout << "our test stack has a capacity of " << test_stack.get_capacity() << endl;
    test_stack.push(4);
    test_stack.display();
    cout << "our test stack has a size of " << test_stack.get_size() << endl;
    cout << "our test stack has a capacity of " << test_stack.get_capacity() << endl;
    cout << test_stack.top() << endl;
    test_stack.pop();
    test_stack.display();
    cout << test_stack.size() << endl;

    //Demonstrate that we can't run out of space now because our stack keeps growing!
    for (int i = 0; i < 20000; i++) 
        test_stack.push(i);

}