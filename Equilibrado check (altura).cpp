#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

pair<int,bool> isBalanced(Node* root) {
    if (!root) return {0, true};
    auto l = isBalanced(root->left);
    auto r = isBalanced(root->right);
    int h = 1 + max(l.first, r.first);
    bool balanced = l.second && r.second && abs(l.first - r.first) <= 1;
    return {h, balanced};
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    cout << (isBalanced(root).second ? "Equilibrado\n" : "No equilibrado\n");
}
