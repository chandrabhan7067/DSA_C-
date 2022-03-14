#include <iostream>
using namespace std;

// Time complexity is   O(n)
// space complexity is   O(1)

// in this algo we print the node which is present in the cyclicle loop 

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

Node *floydLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Loop is present at" << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;
    Insertion(head, 20);
    Insertion(head, 30);
    Insertion(head, 40);
    // tail->next = head->next;
    if (floydLoop(head) != NULL)
    {
        cout << "Loop is present: ";
    }
    else
    {
        cout << "Loop is not present";
    }
}