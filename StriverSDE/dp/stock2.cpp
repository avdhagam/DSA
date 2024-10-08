long f(int ind, int buy, long *values, int n)
{
    if (ind == n)
        return 0;

    long profit = 0;
    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n), 0 + f(ind + 1, 1, values, n));
    }
    else
    {
        profit = max(values[ind] + f(ind + 1, 1, values, n), 0 + f(ind + 1, 0, values, n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    // Write your code here
    return f(0, 1, values, n);
}