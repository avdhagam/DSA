#include <vector>

int lcs(string s, string t)
{
    // Write your code here
    int i = s.size();
    int j = t.size();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));
    for (int ind1 = 1; ind1 <= i; ind1++)
    {
        for (int ind2 = 1; ind2 <= j; ind2++)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else
            {

                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }
    return dp[i][j];
}