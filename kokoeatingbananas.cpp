#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>

int number_of_hours(vector<int> v, int mid)
{
    int hours = 0;
    int m;
    for (auto i : v)
    {
        m =
            hours = hours + static_cast<int>(static_cast<double>(i) / mid);
    }
    return hours;
}

int kokoeatingbananas(vector<int> v, int target)
{
    int l = 1;
    int ans = 0;
    int r = *max_element(v.begin(), v.end());
    int hours = -1;
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        hours = number_of_hours(v, mid);

        if (hours <= target)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (hours > target)
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {30, 11, 23, 4, 20};
    cout << kokoeatingbananas(v, 5) << endl;
}
