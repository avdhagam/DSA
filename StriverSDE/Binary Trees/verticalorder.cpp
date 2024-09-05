/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int vert = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            mp[vert][level].insert(node->val);
            if (node->left)
            {
                q.push({node->left, {vert - 1, level + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {vert + 1, level + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : mp)
        {
            vector<int> level;
            for (auto q : p.second)
            {
                level.insert(level.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};