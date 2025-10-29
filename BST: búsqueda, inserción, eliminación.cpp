#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* search(Node* root, int val) {
    if (!root || root->data == val) return root;
    return (val < root->data) ? search(root->left, val) : search(root->right, val);
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* remove(Node* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) root->left = remove(root->left, val);
    else if (val > root->data) root->right = remove(root->right, val);
    else {
        if (!root->left) { Node* t = root->right; delete root; return t; }
        else if (!root->right) { Node* t = root->left; delete root; return t; }
        Node* succ = minNode(root->right);
        root->data = succ->data;
        root->right = remove(root->right, succ->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 4);

    cout << (search(root, 4) ? "Encontrado\n" : "No encontrado\n");
    root = remove(root, 3);
    cout << (search(root, 3) ? "Encontrado\n" : "No encontrado\n");
}
