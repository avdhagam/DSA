#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int mini = prices[0];
    int n = prices.size();
    int profit = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(prices[i], mini);
    }
    return profit;
}