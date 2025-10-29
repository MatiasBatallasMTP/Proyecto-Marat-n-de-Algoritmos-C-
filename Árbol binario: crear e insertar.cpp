#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node* insertLevelOrder(vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        Node* cur = q.front(); q.pop();
        if (i < vals.size()) { cur->left = new Node(vals[i++]); q.push(cur->left); }
        if (i < vals.size()) { cur->right = new Node(vals[i++]); q.push(cur->right); }
    }
    return root;
}

int main() {
    vector<int> vals = {1,2,3,4,5,6};
    Node* root = insertLevelOrder(vals);
    cout << "Raíz: " << root->data << endl;
}

