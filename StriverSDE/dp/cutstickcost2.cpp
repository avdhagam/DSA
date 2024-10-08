#include <bits/stdc++.h>
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts, dp) + f(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return f(1, c, cuts, dp);
}