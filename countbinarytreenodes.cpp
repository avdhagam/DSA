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

Node *userInput()
{
    int val;
    cout << "enter root value";
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int left;
        cout << "enter left";
        cin >> left;
        if (left != -1)
        {
            Node *leftNode = new Node(left);
            front->left = leftNode;
            q.push(leftNode);
        }

        int right;
        cout << "enter right";
        cin >> right;
        if (right != -1)
        {
            Node *rightNode = new Node(right);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
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

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);
    return 1 + leftcount + rightcount;
}

int main()
{
    Node *root = userInput();
    print(root);
    cout << endl
         << countNodes(root);
}