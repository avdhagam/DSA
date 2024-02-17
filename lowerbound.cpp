#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>

int lowerbound(vector<int> v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    int ans = v[v.size() - 1];
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] >= target)
        {
            ans = min(v[mid], ans);
            r = mid - 1;
        }
        else if (v[mid < target])
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 33};
    cout << lowerbound(v, 3);
}