bool possible(int mid, vector<int> &arr, int k, int m)
{
    int count = 0;
    int nofb = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= mid)
        {
            count++;
        }
        else
        {
            nofb += floor(count / k);
            count = 0;
        }
    }
    nofb += floor(count / k);
    if (nofb >= m)
        return true;
    else
        return false;
}

int roseGarden(vector<int> arr, int k, int m)
{
    long long no = k * 1LL * m * 1LL;
    if (arr.size() < no)
        return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini;
    int high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool val = possible(mid, arr, k, m);
        if (val == true)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}