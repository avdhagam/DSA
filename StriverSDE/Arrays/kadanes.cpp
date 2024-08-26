long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum = 0;
    int maxi = INT_MIN;
    if (n == 0)
        return 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            flag = true;
    }
    if (flag == false)
        return 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}