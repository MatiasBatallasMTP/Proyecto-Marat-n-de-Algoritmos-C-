#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class Queue {
    Node *frontNode, *rearNode;
public:
    Queue(): frontNode(nullptr), rearNode(nullptr) {}
    void enqueue(int val) {
        Node* n = new Node(val);
        if (!rearNode) frontNode = rearNode = n;
        else {
            rearNode->next = n;
            rearNode = n;
        }
    }
    void dequeue() {
        if (!frontNode) return;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
    }
    int front() {
        return frontNode ? frontNode->data : -1;
    }
    bool empty() {
        return frontNode == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    cout << "Frente: " << q.front() << endl;
    q.dequeue();
    cout << "Frente despues de dequeue: " << q.front() << endl;
}
