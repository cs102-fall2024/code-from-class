/**
 * @file class_9a_singular_LL.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief This code demonstrates basic singly linked list operations, including 
 * inserting at the head, inserting at the tail, displaying the list, and 
 * deleting a node by value.
 * @version 0.1
 * @date 2024-10-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Node
 * @brief A class representing a node in a singly linked list.
 * 
 * Each node holds an integer data value and a pointer to the next node.
 */
class Node {
    private:
    int _data;       // The integer data stored in the node
    Node* _next;     // Pointer to the next node in the list

    public:
    /**
     * @brief Constructor for Node class.
     * @param data Integer data to initialize the node with.
     */
    Node(int data) {
        _data = data;
        _next = nullptr;
    }

    /**
     * @brief Gets the data stored in the node.
     * @return Integer data of the node.
     */
    int get_data() {
        return _data;
    }

    /**
     * @brief Sets the data for the node.
     * @param data Integer value to set as the node's data.
     */
    void set_data(int data) {
        _data = data;
    }

    /**
     * @brief Gets the next node in the list.
     * @return Pointer to the next node.
     */
    Node* get_next() {
        return _next;
    }

    /**
     * @brief Sets the next node in the list.
     * @param next Pointer to the next node.
     */
    void set_next(Node* next) {
        _next = next;
    }
};

/**
 * @class SingularLL
 * @brief A singly linked list implementation with basic operations.
 * 
 * Supports operations for inserting nodes at the head and tail,
 * displaying the list, and deleting nodes by value.
 */
class SingularLL {
    private:
        Node* _head; // Pointer to the beginning of the linked list
        Node* _tail; // Pointer to the end of the linked list

    public:
    /**
     * @brief Constructor for SingularLL, initializes an empty list.
     */
    SingularLL() {
        cout << "Constructor called" << endl;
        _head = nullptr;
        _tail = nullptr;
    }

    /**
     * @brief Destructor for SingularLL, frees all nodes in the list.
     */
    ~SingularLL() {
        cout << "Destructor called" << endl;
        Node* current = _head;
        Node* next_node = nullptr;
        while (current != nullptr) { // Traverse and delete each node
            next_node = current->get_next(); // Store next node before deleting current
            delete current; // Free current node
            current = next_node; // Move to next node
        }
    }

    /**
     * @brief Inserts a new node with a given value at the head of the list.
     * @param value Integer value to insert at the head.
     */
    void insert_at_head(int value) {
        Node* new_node = new Node(value);
        new_node->set_next(_head); // Link new node to the current head
        _head = new_node;          // Update head to the new node
        if (_tail == nullptr) {    // If list was empty, update tail as well
            _tail = new_node;
        }
    }

    /**
     * @brief Inserts a new node with a given value at the tail of the list (inefficient).
     * @param data Integer value to insert at the tail.
     */
    void insert_at_tail_bad(int data) {
        Node* new_node = new Node(data);
        if (_head == nullptr) {    // If list is empty, new node becomes head
            _head = new_node;
            return;
        }
        Node* current = _head;
        while (current->get_next() != nullptr) { // Traverse to the last node
            current = current->get_next();
        }
        current->set_next(new_node); // Link last node to new node
    }

    /**
     * @brief Efficiently inserts a new node with a given value at the tail of the list.
     * @param data Integer value to insert at the tail.
     */
    void insert_at_tail(int data) {
        Node* new_node = new Node(data); // Create new node
        if (_tail != nullptr) { // If list is not empty, link current tail to new node
            _tail->set_next(new_node);
        } else { // If list is empty, set head to the new node
            _head = new_node;
        }
        _tail = new_node; // Update tail to the new node
    }

    /**
     * @brief Displays all nodes in the list from head to tail.
     */
    void display() {
        if (_head == nullptr) { // Check if list is empty
            cout << "Yo this list is empty" << endl;
            return;
        }
        Node* current = _head;
        while (current != nullptr) { // Traverse and display each node's data
            cout << current->get_data() << " -> ";
            current = current->get_next();
        }
        cout << "nullptr" << endl;
    }

    /**
     * @brief Deletes the first node in the list that matches the given value.
     * @param value Integer value of the node to delete.
     */
    void delete_by_value(int value) {
        if (_head == nullptr) { // Check if list is empty
            cout << "List is empty, nothing to delete!" << endl;
            return;
        } else if (_head->get_data() == value) { // Check if head matches value
            Node* temp = _head;
            _head = _head->get_next();
            if (_head == nullptr) { // Update tail if list becomes empty
                _tail = nullptr;
            }
            delete temp; // Free memory for deleted node
            return;
        }

        Node* temp = _head;
        /** This while loop has two conditions!
         * Condition 1: the next is not the nullpointer (i.e., we're not at the end)
         * Condition 2: the node that comes next is NOT the node we're looking for
         * So we're basically just looping through until we find the node before 
         * the one we're looking for
         */

        while (temp->get_next() != nullptr && temp->get_next()->get_data() != value) {
            temp = temp->get_next(); // Traverse to node before target node
        }

        //Ok so let's assume we find that node
        if (temp->get_next() != nullptr) { // If node with value found
            Node* node_to_delete = temp->get_next(); //we're going to delete the node that comes next

            temp->set_next(temp->get_next()->get_next()); // Skip over target node

            //What if the node to delete is at the tail?
            if (node_to_delete == _tail) { // Update tail if target is the last node
                _tail = temp;
            }
            delete node_to_delete; // Free memory for deleted node
        } 
        // Oh snap, what if we NEVER find the node? The node does not exist?
        else {
            cout << "Value not found in the list." << endl;
        }
    }
};

// Let's test our code!
int main() {
    // Initialize a new singly linked list
    SingularLL test_list;

    // Display the empty list
    cout << "Initial list (should be empty):" << endl;
    test_list.display();

    // Insert elements at the head of the list
    cout << "Inserting values 1, 2, 3 at the head of the list:" << endl;
    test_list.insert_at_head(1);
    test_list.insert_at_head(2);
    test_list.insert_at_head(3);
    test_list.display();

    // Insert elements at the tail of the list using the inefficient tail insertion
    cout << "Inserting values 4, 5 at the tail of the list (using insert_at_tail_bad):" << endl;
    test_list.insert_at_tail_bad(4);
    test_list.insert_at_tail_bad(5);
    test_list.display();

    // Insert elements at the tail using the efficient tail insertion
    cout << "Inserting values 6, 7 at the tail of the list (using insert_at_tail):" << endl;
    test_list.insert_at_tail(6);
    test_list.insert_at_tail(7);
    test_list.display();

    // Test deleting a node by value (existing values)
    cout << "Deleting node with value 3:" << endl;
    test_list.delete_by_value(3);
    test_list.display();

    cout << "Deleting node with value 7 (tail):" << endl;
    test_list.delete_by_value(7);
    test_list.display();

    // Test deleting a node by value (non-existing value)
    cout << "Trying to delete a node with value 10 (non-existing):" << endl;
    test_list.delete_by_value(10);
    test_list.display();

    // Test deleting the head node
    cout << "Deleting node with value 2 (head):" << endl;
    test_list.delete_by_value(2);
    test_list.display();

    // Test deleting all remaining nodes
    cout << "Deleting remaining nodes to empty the list:" << endl;
    test_list.delete_by_value(1);
    test_list.delete_by_value(6);

    // Confirm the list is empty
    cout << "Final list (should be empty):" << endl;
    test_list.display();

    return 0;
}

