#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    DSU dsu(5);
    dsu.unite(0,1);
    dsu.unite(1,2);
    cout << (dsu.find(2)==dsu.find(0) ? "Mismo conjunto" : "Distintos") << endl;
}
