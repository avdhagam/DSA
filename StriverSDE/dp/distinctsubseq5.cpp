

int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int n = str.size();
    int m = sub.size();

    vector<double> prev(m + 1, 0);
    vector<double> cur(m + 1, 0);
    prev[0] = cur[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
                cur[j] = prev[j - 1] + prev[j];
            else
            {
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }
    return (int)cur[m];
}
