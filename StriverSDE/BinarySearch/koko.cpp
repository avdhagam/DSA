long long findhours(int mid, vector<int> v)
{
    long long hours = 0;
    for (int i = 0; i < v.size(); i++)
    {
        hours += ceil((double)v[i] / (double)mid);
    }
    return hours;
}

int findmax(vector<int> v)
{
    int maxi = -1e9;
    for (int i = 0; i < v.size(); i++)
    {
        maxi = max(v[i], maxi);
    }
    return maxi;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    // Write Your Code Here
    int low = 1;
    int high = findmax(v);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long time = findhours(mid, v);

        if (time <= h)
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