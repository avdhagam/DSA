#include <bits/stdc++.h>
int f(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (tar % arr[0] == 0)
            return tar / arr[0];
        return 1e9;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];

    int notpick = f(ind - 1, tar, arr, dp);
    int pick = 1e9;
    if (arr[ind] <= tar)
    {
        pick = 1 + f(ind, tar - arr[ind], arr, dp);
    }

    return dp[ind][tar] = min(pick, notpick);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = f(n - 1, x, num, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}