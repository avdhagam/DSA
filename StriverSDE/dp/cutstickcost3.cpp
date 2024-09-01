#include <bits/stdc++.h>
int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            int mini = 1e9;
            if (i > j)
                continue;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}