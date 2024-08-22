/****************************************************************

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

*****************************************************************/
#include <stack>
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    // write your code here
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newhead = reverse(slow->next);
    Node *first = head;
    Node *second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newhead);
    return true;
}