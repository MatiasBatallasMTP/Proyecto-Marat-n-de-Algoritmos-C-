#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int d): data(d), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    DNode* head = nullptr;
    DNode* tail = nullptr;
public:
    void push_front(int val) {
        DNode* n = new DNode(val);
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = n;
    }
    void push_back(int val) {
        DNode* n = new DNode(val);
        n->prev = tail;
        if (tail) tail->next = n;
        tail = n;
        if (!head) head = n;
    }
    void print() {
        DNode* cur = head;
        while (cur) { cout << cur->data << " "; cur = cur->next; }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    dl.push_back(1);
    dl.push_back(2);
    dl.push_front(0);
    dl.print();
}
