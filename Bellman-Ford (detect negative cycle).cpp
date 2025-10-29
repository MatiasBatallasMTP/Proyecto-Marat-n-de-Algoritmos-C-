#include <iostream>
#include <vector>
using namespace std;

struct Edge { int u,v,w; };

bool bellmanFord(int V, vector<Edge>& edges, int src){
    vector<int> dist(V,1e9);
    dist[src]=0;
    for(int i=0;i<V-1;i++)
        for(auto e:edges)
            if(dist[e.u]+e.w<dist[e.v]) dist[e.v]=dist[e.u]+e.w;
    for(auto e:edges)
        if(dist[e.u]+e.w<dist[e.v]) return false; // ciclo negativo
    for(int i=0;i<V;i++) cout<<i<<": "<<dist[i]<<endl;
    return true;
}

int main(){
    int V=5;
    vector<Edge> edges={{0,1,6},{0,2,7},{1,2,8},{1,3,5},{1,4,-4},{2,3,-3},{2,4,9},{3,1,-2},{4,0,2},{4,3,7}};
    if(!bellmanFord(V,edges,0)) cout<<"Ciclo negativo detectado"<<endl;
}
