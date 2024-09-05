bool isPalin(string str)
{
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int f(int i, int n, string str, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    string temp = "";
    int mincost = 1e9;
    for (int j = i; j < n; j++)
    {
        temp += str[j];
        if (isPalin(temp))
        {
            int cost = 1 + f(j + 1, n, str, dp);
            mincost = min(cost, mincost);
        }
    }
    return dp[i] = mincost;
}

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.size();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) - 1;
}
