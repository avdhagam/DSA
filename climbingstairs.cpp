#include <stdio.h>
#include <iostream>
using namespace std;

int climbingStairs(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int l = climbingStairs(n - 1);
    int r = climbingStairs(n - 2);
    return l + r;
}

int main()
{
    cout << climbingStairs(3);
}