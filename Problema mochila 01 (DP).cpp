#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> knapsack01(const vector<int>& wt, const vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; ++i)
        for (int w = 0; w <= W; ++w)
            if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
    vector<int> chosen;
    int w = W;
    for (int i = n; i > 0; --i)
        if (dp[i][w] != dp[i-1][w]) {
            chosen.push_back(i-1);
            w -= wt[i-1];
        }
    return {dp[n][W], chosen};
}

int main() {
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int W = 7;
    auto res = knapsack01(wt, val, W);
    cout << "Valor maximo: " << res.first << endl;
}
