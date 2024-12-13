/**
 * @file class_14c_templated_queue.cpp
 * @author Sarah Morrison-Smith
 * @brief A generic queue class
 * @version 0.1
 * @date 2024-12-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue {
    private:
        class Node {
            public:
                T _data;
                Node* _next;
                Node(T value) {
                    _data = value;
                    _next = nullptr;
                }
        };

        Node* _front;
        Node* _rear;
        int _size;

    public:
        Queue() {
            _front = nullptr;
            _rear = nullptr;
            _size = 0;
        }

        ~Queue() {
            while (!is_empty()) {
                dequeue();
            }
        }

        bool is_empty() {
            return _front == nullptr;
        }

        void dequeue() {
            if (is_empty()) {
                cout << "Error, queue is empty!" << endl;
                return;
            }

            Node* temp = _front;
            _front = _front->_next;
            delete temp;
            _size--;
        }

        void enqueue(const T& value) {
            Node* new_node = new Node(value);
            if(is_empty()) {
                _front = _rear = new_node;
            } else {
                _rear->_next = new_node;
                _rear = new_node;
            }
            _size++;
        }

        void print_queue() {
            if (is_empty()) {
                cout << "Queue is empty!" << endl;
                return;
            }

            Node* current = _front;
            while (current != nullptr) {
                cout << current->_data << " -> ";
                current = current->_next;
            }
            cout << endl;
        }
};

int main() {
    //Queue for intergers
    Queue<int> integer_queue;
    integer_queue.enqueue(1);
    integer_queue.enqueue(2);
    integer_queue.enqueue(3);
    integer_queue.print_queue();


    //Queue for strings
    Queue<string> string_queue;
    string_queue.enqueue("Hello");
    string_queue.enqueue("World");
    string_queue.print_queue();

    return 0;
}