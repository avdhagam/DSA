class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1)
            return grid[n - 1][j];
        int down = f(i + 1, j, grid) + grid[i][j];
        int diag = f(i + 1, j + 1, grid) + grid[i][j];
        return min(down, diag);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        return f(0, 0, triangle);
    }
};