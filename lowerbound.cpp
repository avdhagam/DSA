#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

int lowerbound(vector<int> v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    int ans = v[v.end() - 1];

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] < target)
        {
            r = mid - 1;
        }
        else if ()
    }
}