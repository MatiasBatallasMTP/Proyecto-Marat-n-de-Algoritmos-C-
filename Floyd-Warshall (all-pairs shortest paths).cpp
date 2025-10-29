#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(int V, vector<vector<int>>& graph){
    vector<vector<int>> dist = graph;
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9)
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==1e9) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V=4;
    int INF=1e9;
    vector<vector<int>> graph={
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    floydWarshall(V,graph);
}
