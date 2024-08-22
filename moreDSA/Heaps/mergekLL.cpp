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
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    // Write your code here.
    priority_queue<Node *, vector<Node *>, compare> minheap;
    int k = listArray.size();
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minheap.push(listArray[i]);
        }
    }
    Node *head = NULL;
    Node *tail = NULL;

    while (!minheap.empty())
    {
        Node *top = minheap.top();
        minheap.pop();
        if (head == NULL)
        {
            head = top;
            tail = top;
            if (head->next != NULL)
            {
                minheap.push(head->next);
            }
        }

        else
        {
            tail->next = top;
            tail = top;
            if (tail->next != NULL)
            {
                minheap.push(tail->next);
            }
        }
    }
    return head;
}
