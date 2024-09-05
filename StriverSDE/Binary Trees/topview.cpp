vector<int> topView(Node *root)
{
    // Your code here
    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    if (root == NULL)
        return ans;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *node = q.front().first;
        int lev = q.front().second;
        q.pop();

        if (mp.find(lev) == mp.end())
        {
            mp[lev] = node->data;
        }

        if (node->left)
        {
            q.push({node->left, lev - 1});
        }
        if (node->right)
        {
            q.push({node->right, lev + 1});
        }
    }

    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}