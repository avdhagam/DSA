int steps = INT_MAX;
for (int j = 1; j <= k; j++)
{
    if (ind - j >= 0)
    {
        int jump = abs(arr[ind] - arr[ind - j]) + f(ind - j, arr, k, dp);
        steps = min(steps, jump);