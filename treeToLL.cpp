#include <stdio.h>
#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->next = next;
    }
};

Node *userInput()
{
    int val;
    cout << "enter root val " << endl;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int right;
        cout << "enter right value" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *rightnode = new Node(right);
            front->right = rightnode;
            q.push(rightnode);
        }

        int left;
        cout << "enter left value" << endl;
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

vector<Node *> TreeToLLvector(Node *root)
{
    queue<Node *> q;
    vector<Node *> output;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        Node *head = NULL;
        Node *tail = NULL;

        if (front != NULL)
        {
            Node *n = new Node(front->data);
            if (head == NULL)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = tail->next;
            }
            // Now for the BFS part, for each node check if children are present,if so, then push to the queue
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                output.push_back(head);
                head = NULL;
                tail = NULL;
            }
        }
    }
    return output;
}

int main()
{
    Node *root = userInput();
    vector<Node *> ans = TreeToLLvector(root);
    for (auto i : ans)
    {
        cout << i->data << endl;
    }
}