#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

void insertHead(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertTail(Node*& head, int val) {
    Node* n = new Node(val);
    if (!head) { head = n; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void deleteValue(Node*& head, int val) {
    while (head && head->data == val) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == val) {
            Node* t = cur->next;
            cur->next = t->next;
            delete t;
        } else cur = cur->next;
    }
}

void printList(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertHead(head, 3);
    insertTail(head, 5);
    insertTail(head, 10);
    printList(head);
    deleteValue(head, 5);
    printList(head);
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

void insertHead(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertTail(Node*& head, int val) {
    Node* n = new Node(val);
    if (!head) { head = n; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void deleteValue(Node*& head, int val) {
    while (head && head->data == val) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == val) {
            Node* t = cur->next;
            cur->next = t->next;
            delete t;
        } else cur = cur->next;
    }
}

void printList(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertHead(head, 3);
    insertTail(head, 5);
    insertTail(head, 10);
    printList(head);
    deleteValue(head, 5);
    printList(head);
}
