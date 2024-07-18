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
    TreeNode *f(int &i, int bound, vector<int> &A)
    {
        if (i == A.size() || A[i] > bound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(A[i++]);
        root->left = f(i, root->val, A);
        root->right = f(i, bound, A);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return f(i, INT_MAX, preorder);
    }
};