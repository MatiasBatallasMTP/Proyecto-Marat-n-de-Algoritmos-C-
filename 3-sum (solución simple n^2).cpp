#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int s = a[i] + a[l] + a[r];
            if (s == 0) {
                res.push_back({a[i], a[l], a[r]});
                ++l; --r;
                while (l < r && a[l] == a[l - 1]) ++l;
                while (l < r && a[r] == a[r + 1]) --r;
            } else if (s < 0) ++l;
            else --r;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    for (auto &t : res)
        cout << t[0] << "," << t[1] << "," << t[2] << endl;
}
