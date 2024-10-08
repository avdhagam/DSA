

int maxProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));
    int profit = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    profit = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                }
                else
                {

                    profit = max(prices[ind] + ahead[1][cap - 1], 0 + ahead[0][cap]);
                }
                cur[buy][cap] = profit;
            }
        }
        ahead = cur;
    }

    return ahead[1][2];
}