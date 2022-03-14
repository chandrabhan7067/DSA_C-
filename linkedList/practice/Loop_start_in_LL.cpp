#include <iostream>
using namespace std;

// Time complexity is   O(n)
// space complexity is   O(1)

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

void Insertion(Node *&head, int value)
{
    Node *ptr = new Node(value);
    if (head == NULL)
    {
        head = ptr;
        return;
    }

    ptr->next = head;
    head = ptr;
}

Node *NodeInLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

// This function is return that node Which is staring node in the loop

Node *first_Node(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *fast = NodeInLoop(head);
    Node *slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    Insertion(head, 20);
    Insertion(head, 30);
    Insertion(head, 40);
    Insertion(head, 50);
    tail->next = head->next;
    Node *ans = first_Node(head);
    cout << "ans is: " << ans->data;
}