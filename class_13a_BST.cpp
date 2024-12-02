#include <iostream>
#include <vector>
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
    void in_order_to_vector(vector<int>&);

    BinaryNode* _root;
private:
    bool search_recursive(BinaryNode* curr, int x);
    void insert_recursive(BinaryNode*& curr, int x);
    void recursive_print(BinaryNode* curr);
    //HERE
    void in_order_to_vector_recursive(vector<int>& numbers, BinaryNode* curent, int& index);
};

BinarySearchTree::BinarySearchTree() {
    _root = nullptr;
}

void BinarySearchTree::insert(int x) {
    insert_recursive(_root, x);
}

void BinarySearchTree::insert_recursive(BinaryNode*& curr, int x) {
    if (curr == nullptr) {
        curr = new BinaryNode(x);
    }
    else if (x <= curr->_data) { // Insert into the left subtree
        insert_recursive(curr->_left, x);
    }
    else { // Insert into the right subtree
        insert_recursive(curr->_right, x);
    }
}

bool BinarySearchTree::search(int x) {
    // Always start searching at the root
    return search_recursive(_root, x);
}

bool BinarySearchTree::search_recursive(BinaryNode* curr, int x) {
    // Base case: if we reach a nullptr, x isn't in the tree
    if (curr == nullptr)
        return false;

    // Base case: if curr->_data == x, we found it!
    if (curr->_data == x)
        return true;

    // Recursive case: look to the left or the right
    if (x <= curr->_data)
        return search_recursive(curr->_left, x);
    else
        return search_recursive(curr->_right, x);
}

// Here we traverse the nodes in the BST and print them out
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

/**
 * initialize an index variable to track the position of number in vector
 * call a recursive helper that performs the in-order traversal starting from the _root
 * 
 * @param number 
 */
void BinarySearchTree::in_order_to_vector(vector<int>& numbers){
    int index = 0;
    in_order_to_vector_recursive(numbers, _root, index);
}

void BinarySearchTree::in_order_to_vector_recursive(vector<int>& numbers, BinaryNode* current, int& index){
    if(current != nullptr){
        //visit left
        in_order_to_vector_recursive(numbers, current->_left,index);

        //put our node into the vector
        numbers[index] = current->_data;
        index++;

        //visit right
        in_order_to_vector_recursive(numbers, current->_right,index);
    }
}



/**
 * What this needs to do:
 * 1. Create a binary search tree
 * 2. Insert everything in numbers into our tree
 * 3. overwrite the input numbers with our elements in a sorted order -> in order traversal
 * 
 * @param numbers 
 */
void tree_sort(vector<int>& numbers){
    BinarySearchTree carl;

    for(int i = 0; i < numbers.size(); i++)
        carl.insert(numbers[i]);
    
    carl.in_order_to_vector(numbers);
}

int main() {

    vector<int> test_vector = {5, 2, -9, 0, -3, 32, 31, 28, -24, -3, 54};
    tree_sort(test_vector);

    for (int i = 0; i < test_vector.size(); i++)
        cout << " " << test_vector[i];
    cout << endl;


    return 0;
}
