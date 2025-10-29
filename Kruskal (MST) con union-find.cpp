#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int u,v,w; };
bool cmp(Edge a, Edge b){ return a.w < b.w; }

struct DSU{
    vector<int> parent, rank;
    DSU(int n){ parent.resize(n); rank.resize(n,0); for(int i=0;i<n;i++) parent[i]=i; }
    int find(int x){ return parent[x]==x?x:parent[x]=find(parent[x]); }
    bool unite(int x,int y){
        x=find(x); y=find(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) parent[x]=y;
        else{ parent[y]=x; if(rank[x]==rank[y]) rank[x]++; }
        return true;
    }
};

int kruskal(int V, vector<Edge>& edges){
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(V);
    int total=0;
    for(auto e:edges) if(dsu.unite(e.u,e.v)) total+=e.w;
    return total;
}

int main(){
    int V=4;
    vector<Edge> edges={{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    cout << "Peso MST: " << kruskal(V,edges) << endl;
}
