int f(int i, int j, string str1, string str2, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i - 1] == str2[j - 1])
    {
        return dp[i][j] = 0 + f(i - 1, j - 1, str1, str2, dp);
    }
    else
    {
        int insert = 1 + f(i, j - 1, str1, str2, dp);
        int deletee = 1 + f(i - 1, j, str1, str2, dp);
        int replace = 1 + f(i - 1, j - 1, str1, str2, dp);
        return dp[i][j] = min(insert, min(deletee, replace));
    }
}

int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return f(n, m, str1, str2, dp);
}