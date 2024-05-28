#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    vector<int> v = {1, 2, 3};
    int index = 0;
    swap(v[0], v[1]);
    for (auto i : v)
    {
        cout << i << " ";
    }
}