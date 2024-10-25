/**
 * @file class_8b_LL_stack.cpp
 * @author Sarah Morrison-Smith & 102 Class
 * @brief Linked List based Stack
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
using namespace std;

/**
 * @brief Node class for linked-list implementation of a Stack
 * 
 */
class Node {
private:
    int _data;  //data stored in the node
    Node* _next; //pointer to the next node

public:
    /**
     * @brief Construct a new Node object 
     * Note: this is not a default constructor
     * 
     * @param data - the data that goes in the node
     */
    Node(int data) {
        _data = data;
        _next = nullptr;
    }

    /**
     * @brief Displays the node for debugging
     * 
     */
    void display_node() {
        cout << "Node info: " << endl;
        cout << "_data: " << _data << endl;
        cout << "_next: " << _next << endl;
    }

    /**
     * @brief Set the next node
     * 
     * @param next_node - pointer to the next node
     */
    void set_next(Node* next_node) {
        _next = next_node;
    }

    /**
     * @brief Get the next node
     * 
     * @return Node* - pointer to the next node
     */
    Node* get_next() {
        return _next;
    }

    /**
     * @brief Get the data from the Node
     * 
     * @return int - the data in the node
     */
    int get_data() {
        return _data;
    }
};

/**
 * @brief Stack implemented using a linked list
 * 
 */
class LLStack {
private:    
    Node* _top; // pointer to the top of the stack
    int _size; // size of the stack

public:
    /**
     * @brief Construct a new LLStack object
     * Note: this is a default constructor
     */
    LLStack() {
        _top = nullptr; //empty stack, top points to null
        _size = 0; //empty stack, size is 0
    }

    /**
     * @brief Destroy the LLStack object
     * Note if you uncomment the cout, you can see when this is called
     */
    ~LLStack() {
        //cout << "Calling the destructor..." << endl;
        while(_top != nullptr){
            pop();
        }

    }

    /**
     * @brief Pops the top of the stack off
     * 
     */
    void pop() {
        if(!empty()){ 
            Node* old_top = _top;
            _top = _top->get_next();
            //_top = (*_top).get_next();
            _size--;
            delete old_top;
        }
    }
 
    /**
     * @brief Returns the top element of the stack
     * 
     * @return int 
     */
    int top() {
        return _top->get_data();
        //return (*_top).get_data();
    }
    
    /**
     * @brief Displays the stack
     * 
     */
    void display() {
        cout << "Stack | ";
        Node* current_node = _top; 
        while(current_node != nullptr) {
            cout << current_node->get_data();
            cout << " | ";
            //cout << (*current_node).get_data();
            current_node = current_node->get_next();
            //current_node = (*current_node).get_next();
        }
        cout << endl;
    }

    /**
     * @brief Returns the size of the stack
     * 
     * @return unsigned int - the size of the stack
     */
    unsigned int size() {
        return _size;
    }
    
    /**
     * @brief Returns whether the stack is empty
     * 
     * @return true - stack is empty
     * @return false - stack is not empty
     */
    bool empty() {
        return _top == nullptr;
    }

    /**
     * @brief Pushes an item onto the stack
     * 
     * @param item - item to go onto the top of the stack
     */
    void push(int item) {
        Node* node_ptr = new Node(item);
        node_ptr->set_next(_top);
        //(*node_ptr).set_next(_top);
        _top = node_ptr;
        _size++;
    }
};

/**
 * @brief Runs/debugs the stack and node classes
 * 
 * @return int - returns whether the main ran appropriately
 */
int main() {
    // Debugging Nodes
    Node my_node(42);
    my_node.display_node();

    Node other_node(4);
    my_node.set_next(&other_node);
    my_node.display_node();

    Node* my_node_pointer = &my_node;
    my_node_pointer->display_node();
    (*my_node_pointer).display_node();

    cout << my_node_pointer->get_data() << endl;

    // Debugging LLStacks
    LLStack undo;
    undo.push(1);
    undo.display();
    undo.push(2);
    undo.display();

}