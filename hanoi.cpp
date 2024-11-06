/**
 *   Solving Tower of Hanoi
 *   @file main.cpp
 *   @author Darren Strash
 *   @collaborators Built with help of C111 class
 *   @date October 2, 2023
 *
 */
#include <stack>
#include <iostream>

using namespace std;

const int NUM_DISKS = 7;

stack<int> peg1, peg2, peg3;

void move_all(stack<int>& temp_stack, stack<int>& peg) {
    while (temp_stack.size() > 0) {
        peg.push(temp_stack.top());
        temp_stack.pop();
    }
}

void pop_push_print(stack<int>& peg, stack<int>& temp_stack) {
    if (peg.size() > 0) {
        int disk = peg.top();
        peg.pop();
        temp_stack.push(disk);
        cout << disk;
    } else {
        cout << " ";
    }
}

void print_pegs(stack<int>& peg1, stack<int>& peg2, stack<int>& peg3) {
    cout << "Tower of Hanoi:" << endl << "--" << endl << endl;
    stack<int> temp1, temp2, temp3;

    int padding = peg1.size() + peg2.size() + peg3.size()
                    - max(peg1.size(), max(peg2.size(), peg3.size()));
    for (int i = 0; i < padding; i++) {
        cout << endl;
    }
    while (peg1.size() > 0 || peg2.size() > 0 || peg3.size() > 0) {
        pop_push_print(peg1, temp1);
        cout << "\t\t\t";
        pop_push_print(peg2, temp2);
        cout << "\t\t\t";
        pop_push_print(peg3, temp3);
        cout << endl;
    }
    cout << "-\t\t\t-\t\t\t-" << endl;

    move_all(temp1, peg1);
    move_all(temp2, peg2);
    move_all(temp3, peg3);
}

void move_to(stack<int>& src, stack<int>& dest) {
    dest.push(src.top());
    src.pop();
}













void hanoi(int n, stack<int>& src, stack<int>& tmp, stack<int>& dest) {
    if (n > 0) {
        hanoi(n - 1, src, dest, tmp);
        move_to(src, dest);
        cin.get();
        
        print_pegs(peg1, peg2, peg3);
        hanoi(n - 1, tmp, src, dest);
    }
}























int main() {
    //stack<int> peg1, peg2, peg3;
    for (int disk = NUM_DISKS; disk > 0; disk--) {
        peg1.push(disk);
    }

    print_pegs(peg1, peg2, peg3);

    hanoi(peg1.size(), peg1, peg2, peg3);

    print_pegs(peg1, peg2, peg3);
    return 0;
}
