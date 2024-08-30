#include <bits/stdc++.h>
int f(int ind)
{
    if (ind == 0)
        return 1;
    int left = f(ind - 1);
    int right = 0;
    if (ind >= 2)
    {
        right = f(ind - 2);
    }
    return left + right;
}
int countDistinctWays(int nStairs)
{
    //  Write your code here.
    return f(nStairs);
}