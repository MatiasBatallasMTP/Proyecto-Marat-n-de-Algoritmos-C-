#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class Stack {
    Node* topNode;
public:
    Stack() : topNode(nullptr) {}
    void push(int val) {
        Node* n = new Node(val);
        n->next = topNode;
        topNode = n;
    }
    void pop() {
        if (!topNode) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    int top() {
        return topNode ? topNode->data : -1;
    }
    bool empty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top despues de pop: " << s.top() << endl;
}
