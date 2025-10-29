#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void preOrder(Node* n, vector<int>& out) {
    if (!n) return;
    out.push_back(n->data);
    preOrder(n->left, out);
    preOrder(n->right, out);
}

void inOrder(Node* n, vector<int>& out) {
    if (!n) return;
    inOrder(n->left, out);
    out.push_back(n->data);
    inOrder(n->right, out);
}

void postOrder(Node* n, vector<int>& out) {
    if (!n) return;
    postOrder(n->left, out);
    postOrder(n->right, out);
    out.push_back(n->data);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> out;
    
    preOrder(root, out);
    for (int x : out) cout << x << " "; cout << endl;
    out.clear();
    
    inOrder(root, out);
    for (int x : out) cout << x << " "; cout << endl;
    out.clear();
    
    postOrder(root, out);
    for (int x : out) cout << x << " "; cout << endl;
}
