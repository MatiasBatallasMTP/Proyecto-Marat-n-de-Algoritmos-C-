#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool twoSumExists(const vector<int>& a, int target, pair<int,int>& result) {
    unordered_map<int,int> mp;
    for (int i = 0; i < (int)a.size(); ++i) {
        int need = target - a[i];
        if (mp.find(need) != mp.end()) {
            result = {mp[need], i};
            return true;
        }
        mp[a[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    pair<int,int> ans;
    if (twoSumExists(nums, target, ans))
        cout << "Indices: " << ans.first << " y " << ans.second << endl;
    else
        cout << "No encontrado" << endl;
}
