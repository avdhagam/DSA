int f(int ind, int last, vector<vector<int>> &points)
{
    if (ind == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int activity = points[ind][i] + f(ind - 1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    if (n == 0)
        return 0;
    return f(n - 1, 3, points);
}