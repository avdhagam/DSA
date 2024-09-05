int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int N = arr.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxcnt = 0;
    while (i < N)
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxcnt = max(maxcnt, cnt);
    }
    return maxcnt;
}