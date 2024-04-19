#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int laststoneweight(vector<int> arr)
{
    priority_queue<int> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
    }
    return pq.empty() ? 0 : pq.top();
}

int main()
{
    vector<int> arr = {2, 7, 4, 1, 8, 1};
    cout << laststoneweight(arr);
}