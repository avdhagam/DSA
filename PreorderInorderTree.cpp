#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#include <vector>
#include <map>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *helper(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd, map<int, int> &mp);

Node *userInput()
{
    int val;
    cout << "enter root val";
    cin >> val;
    Node *root = new Node(val);

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int left;
        cout << "enter left val" << endl;
        cin >> left;
        if (left != -1)
        {
            Node *leftnode = new Node(left);
            front->left = leftnode;
            q.push(leftnode);
        }

        int right;
        cout << "enter right val" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *rightnode = new Node(right);
            front->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    Node *root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}

Node *helper(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd, map<int, int> &mp)
{
    if (pStart > pEnd || iStart > iEnd)
    {
        return NULL;
    }
    Node *root = new Node(preorder[pStart]);
    int inRoot = mp[root->data];
    int numshift = inRoot - iStart;
    root->left = helper(preorder, pStart + 1, pStart + numshift, inorder, iStart, inRoot - 1, mp);
    root->right = helper(preorder, pStart + numshift + 1, pEnd, inorder, inRoot + 1, iEnd, mp);
    return root;
}

void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    vector<int> preorder = {40, 20, 50, 10, 60, 30};
    vector<int> inorder = {10, 20, 40, 50, 30, 60};
    Node *root = buildTree(preorder, inorder);
    print(root);
}