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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *cur = root;
        TreeNode *prev = NULL;
        while (cur)
        {
            if (cur->left)
            {
                prev = cur->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                if (cur->right)
                {
                    prev->right = cur->right;
                }
                else
                {
                    prev->right = NULL;
                }
                cur->right = cur->left;
                cur->left = NULL;
            }

            cur = cur->right;
        }
    }
};