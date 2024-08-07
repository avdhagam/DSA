bool possible(int mid, vector<int> &stalls, int k)
{
    int count = 1;
    int prevcow = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - prevcow >= mid)
        {
            count++;
            prevcow = stalls[i];
        }
        if (count >= k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(mid, stalls, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}