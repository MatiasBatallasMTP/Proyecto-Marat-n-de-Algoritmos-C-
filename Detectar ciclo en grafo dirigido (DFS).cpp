#include <iostream>
#include <vector>
using namespace std;

bool dfsCycle(int v, vector<vector<int>>& adj, vector<int>& state){
    state[v]=1; // visiting
    for(int u:adj[v]){
        if(state[u]==1) return true;
        if(state[u]==0 && dfsCycle(u,adj,state)) return true;
    }
    state[v]=2; // visited
    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj){
    vector<int> state(V,0);
    for(int i=0;i<V;i++)
        if(state[i]==0 && dfsCycle(i,adj,state)) return true;
    return false;
}

int main(){
    int V=4;
    vector<vector<int>> adj(V);
    adj[0]={1};
    adj[1]={2};
    adj[2]={3};
    adj[3]={1}; // ciclo
    cout << (hasCycle(V,adj) ? "Ciclo detectado" : "Sin ciclo") << endl;
}
