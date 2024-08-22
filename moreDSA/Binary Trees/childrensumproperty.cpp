int isSumProperty(Node *root)
{
    // Add your code here
    if (root == NULL)
        return 0;

    int child = 0;

    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child > root->data)
    {
        root->data = child;
    }
    else
    {
        root->left->data = root->data;
        root->right->data = root->data;
    }

    isSumProperty(root->left);
    isSumProperty(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;

    if (root->left or root->left)
        root->data = tot;
}