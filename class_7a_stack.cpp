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

}