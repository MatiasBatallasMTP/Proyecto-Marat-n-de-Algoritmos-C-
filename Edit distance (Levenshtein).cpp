#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2){
    int m=s1.size(), n=s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for(int i=0;i<=m;i++) dp[i][0]=i;
    for(int j=0;j<=n;j++) dp[0][j]=j;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]= (s1[i-1]==s2[j-1]) ? dp[i-1][j-1] : 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    return dp[m][n];
}

int main(){
    string s1="kitten", s2="sitting";
    cout << "Edit distance: " << editDistance(s1,s2) << endl;
}
