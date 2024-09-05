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

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        string temp = "";
        int mincost = 1e9;
        for (int j = i; j < n; j++)
        {
            temp += str[j];
            if (isPalin(temp))
            {
                int cost = 1 + dp[j + 1];
                mincost = min(cost, mincost);
            }
            dp[i] = mincost;
        }
    }
    return dp[0] - 1;
}
