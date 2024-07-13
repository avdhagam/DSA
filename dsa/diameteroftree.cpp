#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int rightcount = height(root->right);
    int leftcount = height(root->left);
    return 1 + leftcount + rightcount;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    int ans = max(option1, max(option2, option3));
    return ans;
}

int main()
{
    Node *root = userInput();
    cout << diameter(root);
}
