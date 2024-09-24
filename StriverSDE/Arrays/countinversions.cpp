int ccount = 0;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int right = mid + 1;
    int left = low;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            ccount += mid - left + 1;
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergesort(vector<int> &a, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int numberOfInversions(vector<int> &a, int n)
{
    // Write your code here.
    mergesort(a, 0, n - 1);
    return ccount;
}