#include <iostream>
using namespace std;

class BinaryNode {
    public: 
        BinaryNode(int data) {
            _data = data;
            _left = nullptr;
            _right = nullptr;
            _parent = nullptr;
        }
        int _data;
        BinaryNode* _left;
        BinaryNode* _right;
        BinaryNode* _parent;
};

class BinarySearchTree {
    public:
        BinarySearchTree();
        bool search(int x);
        void insert(int x);
        void print();

        BinaryNode* _root;
    private:
        bool search_recursive(BinaryNode* curr, int x);
        void insert_recursive(BinaryNode* &curr, int x);
        void recursive_print(BinaryNode* curr);
};

BinarySearchTree::BinarySearchTree() {
    _root == nullptr;
}

void BinarySearchTree::insert(int x) {
    insert_recursive(_root, x);
}

void BinarySearchTree::insert_recursive(BinaryNode* &curr, int x) {
    if(curr == nullptr) {
        curr = new BinaryNode(x);
    }
    else if (x <= curr->_data) {
        //insert_recursive()
    }
}