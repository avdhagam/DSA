

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    vector<int> cur(n + 1, 0);
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notpick = prev[N];
            int rodlength = ind + 1;
            int pick = -1e9;
            if (N - rodlength >= 0)
            {
                pick = cur[N - rodlength] + price[ind];
            }
            cur[N] = max(notpick, pick);
        }
        prev = cur;
    }

    return prev[n];
}
