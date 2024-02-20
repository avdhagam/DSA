#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
#include <vector>

int numberofdays(vector<int> v, int mid)
{
    int load = 0;
    int days = 1;
    for (auto i : v)
    {
        load += i;
        if (load > mid)
        {
            days++;
            load = i;
        }
    }
    return days;
}

int shipinDdays(vector<int> v, int target)
{
    int ans = 0;
    int l = *max_element(v.begin(), v.end());
    int r = accumulate(v.begin(), v.end(), 0);
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        int days = numberofdays(v, mid);
        if (days <= target)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (days > target)
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipinDdays(v, 5) << endl;
}