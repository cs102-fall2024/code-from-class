/**
 * @file class_9a_singular_LL.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief Singularly linked list
 * @version 0.1
 * @date 2024-10-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

class Node {
    private:
    //data
    int _data;
    //pointer
    Node* _next;

    public:
    //Constructor
    Node(int data){
        _data = data;
        _next = nullptr;
    }

    int get_data() {
        return _data;
    }

    void set_data(int data) {
        _data = data;
    }

    Node* get_next() {
        return _next;
    }

    void set_next(Node* next) {
        _next = next;
    }

};

class SingularLL {
    private:
        Node* _head; // pointer to the beginning of the linked list

    public:
    SingularLL() {
        cout << "Constructor called" << endl;
        _head = nullptr;
    }

    ~SingularLL() {
        cout << "Destructor called" << endl;
        Node* current = _head;
        Node* next_node = nullptr;
        while (current != nullptr) { //while we are not at the end
            next_node = current->get_next(); //get the next while that pointer still exists
            delete current; //delete our current
            current = next_node; // move to the next node
        }
    }

    void insert_at_head(int value) {
        Node* new_node = new Node(value);
        new_node->set_next(_head); //point the new node to preceed head
        _head = new_node;
    }

    void insert_at_tail(int value) {
        Node* new_node = new Node(value);

        //check if the list is empty
        if(_head == nullptr){
            _head = new_node;
            return;
        }

        Node* current = _head;
        //while loop
    }
};

int main() {
    SingularLL test_list;
}