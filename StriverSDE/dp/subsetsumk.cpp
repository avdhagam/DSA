int f(int ind, int s, vector<int> &a)
{
    if (s == 0)
        return 1;
    if (ind == 0)
    {
        if (a[0] == s)
            return 1;
        return 0;
    }

    int notpick = f(ind - 1, s, a);
    int pick = 0;
    if (a[ind] <= s)
    {
        pick = f(ind - 1, s - a[ind], a);
    }
    return pick + notpick;
}

int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    return f(n - 1, k, arr);
}
