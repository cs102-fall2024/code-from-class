/**
 * @file class_14b_linked_list.cpp
 * @brief Singularly linked list but with templates
 */

#include <iostream>
using namespace std;

/**
 * @class Node
 * @brief A template class representing a node in a singly linked list.
 *
 * Each node holds a data value of type T and a pointer to the next node.
 */
template <typename T>
class Node {
private:
    T _data;       // The data stored in the node
    Node* _next;   // Pointer to the next node in the list

public:
    /**
     * @brief Constructor for Node class.
     * @param data Data of type T to initialize the node with.
     */
    Node(T data) {
        _data = data;
        _next = nullptr;
    }

    /**
     * @brief Gets the data stored in the node.
     * @return Data of type T.
     */
    T get_data() { return _data; }

    /**
     * @brief Sets the data for the node.
     * @param data Value of type T to set as the node's data.
     */
    void set_data(T data) { _data = data; }

    /**
     * @brief Gets the next node in the list.
     * @return Pointer to the next node.
     */
    Node* get_next() { return _next; }

    /**
     * @brief Sets the next node in the list.
     * @param next Pointer to the next node.
     */
    void set_next(Node* next) { _next = next; }
};

/**
 * @class SingularLL
 * @brief A template-based singly linked list implementation with basic operations.
 *
 * Supports operations for inserting nodes at the head and tail,
 * displaying the list, and deleting nodes by value.
 */
template <typename T>
class SingularLL {
private:
    Node<T>* _head; // Pointer to the beginning of the linked list
    Node<T>* _tail; // Pointer to the end of the linked list

public:
    /**
     * @brief Constructor for SingularLL, initializes an empty list.
     */
    SingularLL() : _head(nullptr), _tail(nullptr) {
        cout << "Constructor called" << endl;
    }

    /**
     * @brief Destructor for SingularLL, frees all nodes in the list.
     */
    ~SingularLL() {
        cout << "Destructor called" << endl;
        Node<T>* current = _head;
        while (current != nullptr) {
            Node<T>* next_node = current->get_next();
            delete current;
            current = next_node;
        }
    }

    /**
     * @brief Inserts a new node with a given value at the head of the list.
     * @param value Data of type T to insert at the head.
     */
    void insert_at_head(T value) {
        Node<T>* new_node = new Node<T>(value);
        new_node->set_next(_head);
        _head = new_node;
        if (_tail == nullptr) {
            _tail = new_node;
        }
    }

    /**
     * @brief Efficiently inserts a new node with a given value at the tail of the list.
     * @param value Data of type T to insert at the tail.
     */
    void insert_at_tail(T value) {
        Node<T>* new_node = new Node<T>(value);
        if (_tail != nullptr) {
            _tail->set_next(new_node);
        } else {
            _head = new_node;
        }
        _tail = new_node;
    }

    /**
     * @brief Displays all nodes in the list from head to tail.
     */
    void display() {
        if (_head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }
        Node<T>* current = _head;
        while (current != nullptr) {
            cout << current->get_data() << " -> ";
            current = current->get_next();
        }
        cout << "nullptr" << endl;
    }

    /**
     * @brief Deletes the first node in the list that matches the given value.
     * @param value Data of type T of the node to delete.
     */
    void delete_by_value(T value) {
        if (_head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }
        if (_head->get_data() == value) {
            Node<T>* temp = _head;
            _head = _head->get_next();
            if (_head == nullptr) {
                _tail = nullptr;
            }
            delete temp;
            return;
        }

        Node<T>* temp = _head;
        while (temp->get_next() != nullptr && temp->get_next()->get_data() != value) {
            temp = temp->get_next();
        }

        if (temp->get_next() != nullptr) {
            Node<T>* node_to_delete = temp->get_next();
            temp->set_next(node_to_delete->get_next());
            if (node_to_delete == _tail) {
                _tail = temp;
            }
            delete node_to_delete;
        } else {
            cout << "Value not found in the list." << endl;
        }
    }
};

// Example usage
int main() {
    // Create a list for integers
    SingularLL<int> int_list;
    int_list.insert_at_head(10);
    int_list.insert_at_tail(20);
    int_list.insert_at_tail(30);
    int_list.display();

    // Create a list for strings
    SingularLL<string> string_list;
    string_list.insert_at_head("Hello");
    string_list.insert_at_tail("World");
    string_list.insert_at_tail("!");
    string_list.display();

    return 0;
}
