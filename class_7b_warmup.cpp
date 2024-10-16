#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK_SIZE = 1000000;

class Stack { 
    private:
        int _size;
        int _stack[MAX_STACK_SIZE];

    public:
        Stack() {
            _size = 0;
        }

        void push(int item) {
            _stack[_size] = item;
            _size ++;
        }

        void display() {
            cout << "Stack[ ";
            for (int i = 0; i < _size - 1; i++) {
                cout << _stack[i] << " | ";
            }
            cout << _stack[_size -1] << " ] " << endl;
        }

        int top() {
            return _stack[_size - 1];
        }

        void pop() {
            _size --;
        }

        bool empty(){
            return _size == 0;
        }

        int size(){
            return _size;
        }
};


int main() {
    Stack my_cool_stack;  
    my_cool_stack.push(42);   
    my_cool_stack.push(-15);  
    my_cool_stack.push(23);   
    my_cool_stack.push(99);   
    my_cool_stack.pop();
    my_cool_stack.pop();
    my_cool_stack.push(81); 
    my_cool_stack.push(-8);  
    my_cool_stack.push(16);  
    my_cool_stack.pop();
    my_cool_stack.push(75);
    my_cool_stack.pop(); 
    my_cool_stack.push(-100);
    my_cool_stack.push(55);
    my_cool_stack.display();

    return 0;
}
