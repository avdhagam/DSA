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

int f(int i, int n, string str)
{
    if (i == n)
        return 0;
    string temp = "";
    int mincost = 1e9;
    for (int j = i; j < n; j++)
    {
        temp += str[j];
        if (isPalin(temp))
        {
            int cost = 1 + f(j + 1, n, str);
            mincost = min(cost, mincost);
        }
    }
    return mincost;
}

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.size();
    return f(0, n, str) - 1;
}
