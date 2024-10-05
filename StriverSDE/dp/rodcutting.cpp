int f(vector<int> &price, int ind, int n)
{
    if (ind == 0)
        return n * price[0];

    int notpick = f(price, ind - 1, n);
    int rodlength = ind + 1;
    int pick = -1e9;
    if (n - rodlength >= 0)
    {
        pick = f(price, ind, n - rodlength) + price[ind];
    }
    return max(notpick, pick);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return f(price, n - 1, n);
}
