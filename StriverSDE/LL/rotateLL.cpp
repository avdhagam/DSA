/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node *findkthnode(Node *head, int k)
{
    int cnt = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (cnt == k)
        {
            return temp;
        }
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node *rotate(Node *head, int k)
{
    // Write your code here.
    if (head == NULL || k == 0)
        return head;

    int len = 1;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }

    if (k % len == 0)
        return head;
    k = k % len;

    Node *newhead = findkthnode(head, len - k);
    tail->next = head;
    head = newhead->next;
    newhead->next = NULL;

    return head;
}