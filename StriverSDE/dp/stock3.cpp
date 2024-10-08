#include <vector>
long f(int ind, int buy, long *values, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit = 0;
    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n, dp), 0 + f(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + f(ind + 1, 1, values, n, dp), 0 + f(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return f(0, 1, values, n, dp);
}