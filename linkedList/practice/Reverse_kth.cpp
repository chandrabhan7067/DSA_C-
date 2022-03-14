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
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

Node *Reverse(Node *&head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *pre = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
        cnt++;
    }

    if (forward != NULL)
    {
        curr->next = Reverse(forward, k);
    }
    return pre;
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
    head = Reverse(head, 2);
    cout << endl;
    print(head);
}