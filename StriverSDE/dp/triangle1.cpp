class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size();
        if (i == n - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = INT_MAX;
        int diag = INT_MAX;
        if (i + 1 < n)
            down = f(i + 1, j, grid, dp) + grid[i][j];
        if (i + 1 < n && j + 1 < grid[i + 1].size())
            diag = f(i + 1, j + 1, grid, dp) + grid[i][j];
        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }
};