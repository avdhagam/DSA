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
    cout << "enter root val" << endl;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
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
    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int rightcount = height(root->right);
    int leftcount = height(root->left);
    return 1 + rightcount + leftcount;
}

int main()
{
    Node *root = UserInput();
    cout << height(root);
}