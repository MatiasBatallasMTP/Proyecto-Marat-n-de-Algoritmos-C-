#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
    vector<list<int>> table;
    int size;
public:
    HashTable(int s): size(s) { table.resize(s); }

    int hash(int key) { return key % size; }

    void insert(int key) { table[hash(key)].push_back(key); }

    bool search(int key) {
        for(int k : table[hash(key)]) if(k==key) return true;
        return false;
    }

    void remove(int key) {
        table[hash(key)].remove(key);
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(3);
    cout << ht.search(10) << " " << ht.search(2) << endl;
    ht.remove(10);
    cout << ht.search(10) << endl;
}
