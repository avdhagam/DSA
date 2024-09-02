#include <bits/stdc++.h>
int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = (a[i - 1] * a[ind] * a[j + 1]) + f(i, ind - 1, a, dp) + f(ind + 1, j, a, dp);
        maxi = max(cost, maxi);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int> &a)
{
    // Write your code here.
    a.push_back(1);
    a.insert(a.begin(), 1);
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(1, a.size() - 2, a, dp);
}