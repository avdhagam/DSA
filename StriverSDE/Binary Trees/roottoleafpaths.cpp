class Solution
{
public:
    void f(Node *root, vector<vector<int>> &ans, vector<int> ds)
    {
        if (root == NULL)
            return;

        ds.push_back(root->data);
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(ds);
            return;
        }

        if (root->left)
            f(root->left, ans, ds);
        if (root->right)
            f(root->right, ans, ds);
    }
    vector<vector<int>> Paths(Node *root)
    {
        // code here
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        vector<int> ds;
        f(root, ans, ds);
        return ans;
    }
};
