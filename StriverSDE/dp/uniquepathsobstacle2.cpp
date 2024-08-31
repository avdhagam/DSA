class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                int top = 0;
                int down = 0;

                if (i > 0)
                    top = dp[i - 1][j];
                if (j > 0)
                    down = dp[i][j - 1];

                dp[i][j] = top + down;
            }
        }
        return dp[n - 1][m - 1];
    }
};