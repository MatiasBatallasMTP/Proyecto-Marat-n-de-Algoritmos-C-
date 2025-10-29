#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P; // (dist, node)

void dijkstra(int V, vector<vector<P>>& adj, int src){
    vector<int> dist(V,1e9);
    dist[src]=0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<V;i++) cout<<i<<": "<<dist[i]<<endl;
}

int main(){
    int V=5;
    vector<vector<P>> adj(V);
    adj[0]={{1,10},{3,5}};
    adj[1]={{2,1},{3,2}};
    adj[2]={{4,4}};
    adj[3]={{1,3},{2,9},{4,2}};
    adj[4]={{0,7},{2,6}};
    dijkstra(V,adj,0);
}
