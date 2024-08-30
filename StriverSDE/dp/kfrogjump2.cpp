int f(int ind, vector<int> arr, int k)
{
    if (ind == 0)
        return 0;
    int steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = abs(arr[ind] - arr[ind - j]) + f(ind - j, arr, k);
            steps = min(steps, jump);
        }
    }
    return steps;
}
int minimizeCost(vector<int> &arr, int &k)
{
    // Code here
    int n = arr.size();
    return f(n - 1, arr, k);
}