#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int l, int r){
    while(l<r) if(s[l++]!=s[r--]) return false;
    return true;
}

void partitionHelper(string s, int start, vector<string>& path, vector<vector<string>>& res){
    if(start==s.size()){ res.push_back(path); return; }
    for(int i=start;i<s.size();i++){
        if(isPalindrome(s,start,i)){
            path.push_back(s.substr(start,i-start+1));
            partitionHelper(s,i+1,path,res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    partitionHelper(s,0,path,res);
    return res;
}

int main(){
    string s="aab";
    auto res=partition(s);
    for(auto &v:res){
        for(string t:v) cout<<t<<" ";
        cout<<endl;
    }
}
