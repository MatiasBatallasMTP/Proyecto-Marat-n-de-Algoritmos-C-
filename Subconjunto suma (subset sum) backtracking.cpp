#include <iostream>
#include <vector>
using namespace std;

bool subsetSumBacktrack(const vector<int>& nums, int target, vector<int>& sol) {
    function<bool(int,int)> dfs = [&](int i, int sum) {
        if (sum == target) return true;
        if (i == (int)nums.size() || sum > target) return false;
        sol.push_back(nums[i]);
        if (dfs(i+1, sum + nums[i])) return true;
        sol.pop_back();
        return dfs(i+1, sum);
    };
    return dfs(0, 0);
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> sol;
    if (subsetSumBacktrack(nums, target, sol)) {
        cout << "Encontrado: ";
        for (int x : sol) cout << x << " ";
        cout << endl;
    } else cout << "No encontrado\n";
}
