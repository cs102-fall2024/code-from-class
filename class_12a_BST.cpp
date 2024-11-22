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
        ~BinarySearchTree();

        BinaryNode* _root;
    private:
        bool search_recursive(BinaryNode* curr, int x);
        void insert_recursive(BinaryNode* &curr, int x);
        void recursive_print(BinaryNode* curr);
        void recursive_destructor(BinaryNode* curr);
};

BinarySearchTree::BinarySearchTree() {
    _root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    recursive_destructor(_root);
}

void BinarySearchTree::recursive_destructor(BinaryNode* curr){
    if (curr == nullptr)
        return;
    
    //Recursive cases
    recursive_destructor(curr->_left);
    recursive_destructor(curr->_right);
    cout << "about to delete node with data: " << curr->_data << endl;
    delete curr;
}

void BinarySearchTree::insert(int x) {
    insert_recursive(_root, x);
}

void BinarySearchTree::insert_recursive(BinaryNode* &curr, int x) {
    if(curr == nullptr) {
        curr = new BinaryNode(x);
    }
    
    //New code starts here!
    //If x is smaller than the current node, we insert into left subtree
    else if (x <= curr->_data) {
        insert_recursive(curr->_left, x);
    }
    //Otherwise we insert into the right subtree
    else {
        insert_recursive(curr->_right, x);
    }
}

bool BinarySearchTree::search(int x) {
    //Always start searching at the root
    return search_recursive(_root,x);
}

bool BinarySearchTree::search_recursive(BinaryNode* curr, int x) {
    //Base case, if we have reached a nullptr, x isn't in the tree
    if (curr == nullptr)
        return false;
    
    //Base case: if curr->_data == x, we found it!
    if (curr->_data == x)
        return true;
    
    //Recursive case: look to the left or the right depending on if x is <= or > data
    if (x <= curr->_data)
        return search_recursive(curr->_left, x);
    else
        return search_recursive(curr->_right, x);
}

//Here we traverse the nodes in the BST and print them out
void BinarySearchTree::print() {
    cout << "Tree: ";
    recursive_print(_root);
    cout << endl;
}

void BinarySearchTree::recursive_print(BinaryNode* curr) {
    if (curr != nullptr) {
        cout << curr->_data << " ";
        recursive_print(curr->_left);
        recursive_print(curr->_right);
    }
}

int main() {
    BinarySearchTree bst;
    
    int tree_data[20] = {54, 67, 100, 2, 5, 6, 19, 12, 1009, 143, 51, 67, 12, 23, 53, 87, 97, 86, 99, 5};

    for (int i = 0; i < 20; i++) {
        bst.insert(tree_data[i]);
    }

    bst.print();

    return 0;
}