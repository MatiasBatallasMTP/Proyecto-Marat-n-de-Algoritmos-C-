#include <iostream>
#include <vector>
using namespace std;

void setDiagonals(vector<vector<int>>& matrix, int val){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        matrix[i][i]=val;           // diagonal principal
        matrix[i][n-1-i]=val;       // diagonal secundaria
    }
}

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    setDiagonals(mat,0);
    for(auto row:mat){
        for(int x:row) cout<<x<<" ";
        cout<<endl;
    }
}
