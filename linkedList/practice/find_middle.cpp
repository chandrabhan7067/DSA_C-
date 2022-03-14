#include <iostream>
using namespace std;

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

void print(Node *&head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// time compexity is o(n)

void Find_middle(Node *&head)
{
    Node *p = head;
    int count = 0;

    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    cout << count << endl;
    int mid = count / 2;
    cout << mid << endl;
    p = head;
    int j = 0;
    while (j != mid)
    {
        p = p->next;
        j++;
    }
    cout << "Mid node is:" << p->data;
}

// Another solution

void Middle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Middle is " << head;
    }
    if (head->next->next == NULL)
    {
        cout << "Middle is " << head->next;
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
    }
    cout << "Middle is " << slow->data;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    print(head);
    Find_middle(head);
    cout << endl;
    Middle(head);
    cout << endl;
}