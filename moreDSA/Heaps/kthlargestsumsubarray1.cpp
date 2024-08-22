#include <algorithm>
int getKthLargest(vector<int> &arr, int k)
{
    //	Write your code here.
    int n = arr.size();
    vector<int> sumset;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumset.push_back(sum);
        }
    }
    sort(sumset.begin(), sumset.end());
    return sumset[sumset.size() - k];
}