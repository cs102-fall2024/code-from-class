/**
 * @file class_10a_LL_recursive.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief Adding recursive methods to our Linked List
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

class Node {
    private:
    int _data;
    Node* _next;

    public:
    Node(int data);

    int get_data();
    void set_data(int data);
    Node* get_next();
    void set_next(Node* next);
};

Node::Node(int data) {
    _data = data;
    _next = nullptr;
}

int Node::get_data() {
    return _data;
}

void Node::set_data(int data) {
    _data = data;
}

Node* Node::get_next() {
    return _next;
}

void Node::set_next(Node* next) {
    _next = next;
}

class SingularLL {
    private:
    Node* _head;
    Node* _tail;

    public:
    SingularLL();
    ~SingularLL();
    void insert_at_head(int value);
    void insert_at_tail_bad(int data);
    void insert_at_tail(int data);
    void display();
    void delete_by_value(int value);
    int size();
    int size_helper(Node* current_node);
    void clear(Node* current_node);
};

SingularLL::SingularLL() {
    cout << "Constructor called" << endl;
    _head = nullptr;
    _tail = nullptr;
}

/*SingularLL::~SingularLL() {
    cout << "Destructor called" << endl;
    Node* current = _head;
    Node* next_node = nullptr;
    while (current != nullptr) {
        next_node = current->get_next();
        delete current;
        current = next_node;
    }
}*/

SingularLL::~SingularLL() {
    clear(_head);
}

/**
 * @brief Fixed the clear function with the help of Madeline 
 * 
 * @param current_node 
 */
void SingularLL::clear(Node* current_node){
    //Previous code stopped at the nullptr when we wanted to stop BEFORE the nullptr
    if(current_node->get_next() != nullptr) {
        clear(current_node->get_next());
        delete current_node;
    }
}

void SingularLL::insert_at_head(int value) {
    Node* new_node = new Node(value);
    new_node->set_next(_head);
    _head = new_node;
    if (_tail == nullptr) {
        _tail = new_node;
    }
}

void SingularLL::insert_at_tail_bad(int data) {
    Node* new_node = new Node(data);
    if (_head == nullptr) {
        _head = new_node;
        return;
    }
    Node* current = _head;
    while (current->get_next() != nullptr) {
        current = current->get_next();
    }
    current->set_next(new_node);
}

void SingularLL::insert_at_tail(int data) {
    Node* new_node = new Node(data);
    if (_tail != nullptr) {
        _tail->set_next(new_node);
    } else {
        _head = new_node;
    }
    _tail = new_node;
}

void SingularLL::display() {
    if (_head == nullptr) {
        cout << "Yo this list is empty" << endl;
        return;
    }
    Node* current = _head;
    while (current != nullptr) {
        cout << current->get_data() << " -> ";
        current = current->get_next();
    }
    cout << "nullptr" << endl;
}

void SingularLL::delete_by_value(int value) {
    if (_head == nullptr) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    } else if (_head->get_data() == value) {
        Node* temp = _head;
        _head = _head->get_next();
        if (_head == nullptr) {
            _tail = nullptr;
        }
        delete temp;
        return;
    }

    Node* temp = _head;
    while (temp->get_next() != nullptr && temp->get_next()->get_data() != value) {
        temp = temp->get_next();
    }

    if (temp->get_next() != nullptr) {
        Node* node_to_delete = temp->get_next();
        temp->set_next(temp->get_next()->get_next());
        if (node_to_delete == _tail) {
            _tail = temp;
        }
        delete node_to_delete;
    } else {
        cout << "Value not found in the list." << endl;
    }


}

int SingularLL::size() {
    return size_helper(_head);
    /*int size = size_helper(_head);
    return size;*/
}

int SingularLL::size_helper(Node* current_node) {
    if(current_node == nullptr)
        return 0;
    return 1 + size_helper(current_node->get_next());

}



int main() {
    SingularLL test_list;

    //cout << "Initial list (should be empty):" << endl;
    //test_list.display();

    //cout << "Inserting values 1, 2, 3 at the head of the list:" << endl;
    test_list.insert_at_head(1);
    test_list.insert_at_head(2);
    test_list.insert_at_head(3);
    //test_list.display();

    //cout << "Inserting values 4, 5 at the tail of the list (using insert_at_tail_bad):" << endl;
    test_list.insert_at_tail_bad(4);
    test_list.insert_at_tail_bad(5);
    //test_list.display();

    //cout << "Inserting values 6, 7 at the tail of the list (using insert_at_tail):" << endl;
    test_list.insert_at_tail(6);
    test_list.insert_at_tail(7);
    test_list.display();

    /*cout << "Deleting node with value 3:" << endl;
    test_list.delete_by_value(3);
    test_list.display();

    cout << "Deleting node with value 7 (tail):" << endl;
    test_list.delete_by_value(7);
    test_list.display();

    cout << "Trying to delete a node with value 10 (non-existing):" << endl;
    test_list.delete_by_value(10);
    test_list.display();
    cout<< "Size of list is: "<< test_list.size() <<endl;

    cout << "Deleting node with value 2 (head):" << endl;
    test_list.delete_by_value(2);
    test_list.display();

    cout << "Deleting remaining nodes to empty the list:" << endl;
    test_list.delete_by_value(1);
    test_list.delete_by_value(6);

    cout << "Final list (should be empty):" << endl;*/
    test_list.display();
    //cout<< "Size of list is: "<< test_list.size() <<endl;

    return 0;
}
