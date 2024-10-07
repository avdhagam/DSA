int f(int i, int j, string str, string sub)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (str[i] == sub[j])
        return f(i - 1, j - 1, str, sub) + f(i - 1, j, str, sub);
    else
    {
        return f(i - 1, j, str, sub);
    }
}

int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int n = str.size();
    int m = sub.size();
    return f(n - 1, m - 1, str, sub);
}
