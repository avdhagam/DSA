//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// } Driver Code Ends
/* BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
    void getPred(Node *root, Node *&pre, int key)
    {
        pre = NULL;
        while (root != NULL)
        {
            if (root->key >= key)
            {
                root = root->left;
            }
            else
            {
                pre = root;
                root = root->right;
            }
        }
    }

    void getSuc(Node *root, Node *&suc, int key)
    {
        suc = NULL;
        while (root != NULL)
        {
            if (root->key <= key)
            {
                root = root->right;
            }
            else
            {
                suc = root;
                root = root->left;
            }
        }
    }
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        getPred(root, pre, key);
        getSuc(root, suc, key);

        // Your code goes here
    }
};