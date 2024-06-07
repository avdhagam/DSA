#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

// recursion
int f(int index, int last, vector<vector<int>> &points)
{
    if (index == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[index][task] + f(index - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

int f1(int index, int last, vector<vector<int>> points, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if (dp[index][last] != -1)
    {
        return dp[index][last];
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[index][task] + f1(index - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[index][last] = maxi;
}

void ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << f(n - 1, 3, points) << endl;
    cout << f1(n - 1, 3, points, dp);
}

int main()
{
    vector<vector<int>> points = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    ninjaTraining(4, points);
}