#include <algorithm>

int count(vector<int> &arr, int n, int x)
{
    // Write Your Code Here
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
    return ub - lb + 1;
}
