/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *fast = head;
    for (int i = 0; i < K; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        return head->next;
    }
    Node *slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *delnode = slow->next;
    slow->next = slow->next->next;
    free(delnode);
    return head;
}
