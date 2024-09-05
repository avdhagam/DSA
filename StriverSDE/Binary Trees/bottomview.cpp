class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int vert = q.front().second;
            mp[vert] = node->data;
            q.pop();
            if (node->left)
            {
                q.push({node->left, vert - 1});
            }
            if (node->right)
            {
                q.push({node->right, vert + 1});
            }
        }

        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};