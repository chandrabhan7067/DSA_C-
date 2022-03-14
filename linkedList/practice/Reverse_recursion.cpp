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

void print(Node *head)
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Time and space complexity of recursive solution is  o(n)

void reverse(Node *&head, Node *curr, Node *prev)
{

    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    head->next = second;
    second->next = third;
    third->next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    print(head);
    cout<<"After reverse "<<endl;
    reverse(head, curr, prev);
    print(head);
}