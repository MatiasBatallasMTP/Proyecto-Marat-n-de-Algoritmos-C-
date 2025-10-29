#include <iostream>
#include <vector>
using namespace std;

struct SparseEntry { int row, col, val; };

vector<SparseEntry> toSparse(vector<vector<int>>& mat){
    vector<SparseEntry> res;
    for(int i=0;i<mat.size();i++)
        for(int j=0;j<mat[0].size();j++)
            if(mat[i][j]!=0) res.push_back({i,j,mat[i][j]});
    return res;
}

int main(){
    vector<vector<int>> mat={{0,0,3},{4,0,0},{0,0,0}};
    auto sparse=toSparse(mat);
    for(auto e:sparse) cout<<"("<<e.row<<","<<e.col<<","<<e.val<<") ";
    cout<<endl;
}
