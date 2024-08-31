class Solution
{
public:
    int f(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        int top = f(i - 1, j);
        int left = f(i, j - 1);

        return top + left;
    }
    int uniquePaths(int m, int n)
    {
        return f(m - 1, n - 1);
    }
};