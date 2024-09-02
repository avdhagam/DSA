#include <stack>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root)
{
    return (root->left == NULL && root->right == NULL);
}

void addLeft(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *cur = root->left;
    while (cur != NULL)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void addRight(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *cur = root->right;
    stack<int> st;
    while (cur)
    {
        if (!isLeaf(cur))
            st.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        res.push_back(val);
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (root == NULL)
        return res;
    res.push_back(root->data);
    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);
    return res;
}
