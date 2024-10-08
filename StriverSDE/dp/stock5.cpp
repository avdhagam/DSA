
#include <vector>

long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

    long profit = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
            {
                profit = max(-values[ind] + ahead[0], 0 + ahead[1]);
            }
            else
            {
                profit = max(values[ind] + ahead[1], 0 + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }

    return ahead[1];
}