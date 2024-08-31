bool f(int ind, int sum, vector<int> arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (ind < 0)
        return false;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    bool pick = false;
    if (sum - arr[ind] >= 0)
        pick = f(ind - 1, sum - arr[ind], arr, dp);
    bool notpick = f(ind - 1, sum, arr, dp);

    return dp[ind][sum] = pick || notpick;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n - 1, sum, arr, dp);
}