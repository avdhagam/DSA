int f(int ind, int buy, int cap, vector<int> prices, int n)
{
    if (ind == n)
        return 0;
    if (cap == 0)
        return 0;

    int profit = 0;

    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, n), 0 + f(ind + 1, 1, cap, prices, n));
    }
    else
    {
        profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n), 0 + f(ind + 1, 0, cap, prices, n));
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    return f(0, 1, 2, prices, n);
}