#include <stdio.h>
#include <iostream>
using namespace std;
#include <queue>

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

Node *UserInput()
{
    int val;
    cout << "enter root" << endl;
    cin >> val;
    Node *Root = new Node(val);
    queue<Node *> q;
    q.push(Root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int right;
        cout << "enter right" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *rightnode = new Node(right);
            front->right = rightnode;
            q.push(rightnode);
        }

        int left;
        cout << "enter left" << endl;
        cin >> left;
        if (left != -1)
        {
            Node *leftnode = new Node(left);
            front->left = leftnode;
            q.push(leftnode);
        }
    }
    return Root;
}

void helper(Node *root, int currentLevel, int maxlevel);

void leftview(Node *root)
{
    int maxlevel = 0;
    helper(root, 1, maxlevel);
}

void helper(Node *root, int currentLevel, int maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (currentLevel > maxlevel)
    {
        cout << root->data << endl;
        maxlevel = currentLevel;
    }
    helper(root->left, currentLevel + 1, maxlevel);
    helper(root->right, currentLevel + 1, maxlevel);
}

int main()
{
    Node *root = UserInput();
    leftview(root);
}