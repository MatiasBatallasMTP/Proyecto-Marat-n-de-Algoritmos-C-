#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P; // (weight, node)

int prim(int V, vector<vector<P>>& adj){
    vector<bool> vis(V,false);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,0});
    int total=0;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        total+=w;
        for(auto [v,wt]: adj[u]) if(!vis[v]) pq.push({wt,v});
    }
    return total;
}

int main(){
    int V=5;
    vector<vector<P>> adj(V);
    adj[0]={{1,2},{3,6}};
    adj[1]={{0,2},{2,3},{3,8},{4,5}};
    adj[2]={{1,3},{4,7}};
    adj[3]={{0,6},{1,8},{4,9}};
    adj[4]={{1,5},{2,7},{3,9}};
    cout << "Peso MST: " << prim(V,adj) << endl;
}
