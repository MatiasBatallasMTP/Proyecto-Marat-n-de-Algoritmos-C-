#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoDFS(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s) {
    visited[v] = true;
    for(int u : adj[v]) if(!visited[u]) topoDFS(u, adj, visited, s);
    s.push(v);
}

void topoSort(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V,false);
    stack<int> s;
    for(int i=0;i<V;i++) if(!visited[i]) topoDFS(i,adj,visited,s);
    while(!s.empty()){ cout<<s.top()<<" "; s.pop(); }
    cout<<endl;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5] = {2,0};
    adj[4] = {0,1};
    adj[2] = {3};
    adj[3] = {1};
    topoSort(V,adj);
}
