#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr){}
};

Node* mergeKLists(vector<Node*>& lists){
    auto cmp=[](Node* a, Node* b){ return a->val>b->val; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
    for(Node* n: lists) if(n) pq.push(n);
    Node dummy(0), *cur=&dummy;
    while(!pq.empty()){
        Node* n=pq.top(); pq.pop();
        cur->next=n;
        cur=n;
        if(n->next) pq.push(n->next);
    }
    return dummy.next;
}

int main(){
    Node* a=new Node(1); a->next=new Node(4); a->next->next=new Node(5);
    Node* b=new Node(1); b->next=new Node(3); b->next->next=new Node(4);
    Node* c=new Node(2); c->next=new Node(6);
    vector<Node*> lists={a,b,c};
    Node* merged=mergeKLists(lists);
    while(merged){ cout<<merged->val<<" "; merged=merged->next; } cout<<endl;
}
