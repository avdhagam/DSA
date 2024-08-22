int findMin(vector<int> &arr)
{
    // Write your code here.
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }
        ans = min(ans, arr[mid]);

        if (arr[mid] <= arr[high])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}