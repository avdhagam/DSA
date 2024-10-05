int f(vector<int> &price, int ind, int n, vector<vector<int>> &dp)
{
    if (ind == 0)
        return n * price[0];
    if (dp[ind][n] != -1)
        return dp[ind][n];

    int notpick = f(price, ind - 1, n, dp);
    int rodlength = ind + 1;
    int pick = -1e9;
    if (n - rodlength >= 0)
    {
        pick = f(price, ind, n - rodlength, dp) + price[ind];
    }
    return dp[ind][n] = max(notpick, pick);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(price, n - 1, n, dp);
}
