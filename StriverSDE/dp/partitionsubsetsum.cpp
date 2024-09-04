#include <numeric>

bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[ind] == target;
    bool taken = false;
    if (arr[ind] <= target)
    {
        taken = f(ind - 1, target - arr[ind], arr);
    }
    bool nottaken = f(ind - 1, target, arr);
    return taken || nottaken;
}

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int s = accumulate(arr.begin(), arr.end(), 0);
    if (s % 2 != 0)
        return false;
    if (f(n - 1, s / 2, arr) == true)
        return true;
    else
        return false;
}
