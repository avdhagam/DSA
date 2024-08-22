#include <bits/stdc++.h>

class node
{
public:
    int data;
    int i;
    int j;
    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    priority_queue<node *, vector<node *>, compare> minheap;
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minheap.push(temp);
    }
    vector<int> ans;
    while (minheap.size() > 0)
    {
        node *temp = minheap.top();
        ans.push_back(temp->data);

        minheap.pop();

        int i = temp->i;
        int j = temp->j;

        if (j + 1 < kArrays[i].size())
        {
            node *temp2 = new node(kArrays[i][j + 1], i, j + 1);
            minheap.push(temp2);
        }
    }
    return ans;
}
