#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix){
    int m=matrix.size(), n=matrix[0].size();
    vector<bool> row(m,false), col(n,false);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(matrix[i][j]==0){ row[i]=true; col[j]=true; }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(row[i]||col[j]) matrix[i][j]=0;
}

int main(){
    vector<vector<int>> mat={{1,2,3},{4,0,6},{7,8,9}};
    setZeroes(mat);
    for(auto row:mat){
        for(int x:row) cout<<x<<" ";
        cout<<endl;
    }
}
