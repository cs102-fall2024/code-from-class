#include <iostream>
#include <vector>

using namespace std;

class HashTableChaining {
private:
    vector<vector<int>> _table;
    int _size;

public:
    HashTableChaining(int input_size) { 
        _size = input_size; 
        _table = vector<vector<int>>(input_size);
}

    int hash_function(int key) {
        return key % _size;
    }

    void insert(int key) {
        int index = hash_function(key);
        _table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < _size; ++i) {
            cout << "[" << i <<"]: ";
            for (int j : _table[i]) {
                cout << j << " -> ";
            }
        }
        cout << endl;
    }
};

int main() {
    HashTableChaining ht(7);
    ht.insert(10); //3
    ht.insert(20); //6
    ht.insert(15); //1
    ht.insert(30); //3

    ht.display();
    return 0;
}