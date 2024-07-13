#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

int searchinsert(vector<int> v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    int ans = v[v.size() - 1];
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        if (v[mid] >= target)
        {
            ans = min(ans, v[mid]);
            r = mid - 1;
        }
        else if (v[mid] < target)
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 3, 5, 6};
    cout << searchinsert(v, 4);
}