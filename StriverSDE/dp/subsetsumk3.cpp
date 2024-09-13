

int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= k; s++)
        {
            int notpick = dp[i - 1][s];
            int pick = 0;
            if (arr[i] <= s)
            {
                pick = dp[i - 1][s - arr[i]];
            }

            dp[i][s] = pick + notpick;
        }
    }

    return dp[n - 1][k];
}
