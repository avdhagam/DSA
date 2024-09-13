int f(int ind, int s, vector<int> &a, vector<vector<int>> &dp)
{
    if (s == 0)
        return 1;
    if (ind == 0)
    {
        if (a[0] == s)
            return 1;
        return 0;
    }
    if (dp[ind][s] != -1)
        return dp[ind][s];

    int notpick = f(ind - 1, s, a, dp);
    int pick = 0;
    if (a[ind] <= s)
    {
        pick = f(ind - 1, s - a[ind], a, dp);
    }
    return dp[ind][s] = pick + notpick;
}

int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}
