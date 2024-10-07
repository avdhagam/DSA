

int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
