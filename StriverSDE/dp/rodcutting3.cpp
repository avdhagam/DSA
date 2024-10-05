

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notpick = dp[ind - 1][N];
            int rodlength = ind + 1;
            int pick = -1e9;
            if (N - rodlength >= 0)
            {
                pick = dp[ind][N - rodlength] + price[ind];
            }
            dp[ind][N] = max(notpick, pick);
        }
    }

    return dp[n - 1][n];
}
