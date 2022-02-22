#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;

    Node(int value)
    {
        this->data = value;
        this->Next = NULL;
    }
};

void print(Node *&head)
{
    Node *p = head;

    while (p->Next != head)
    {
        cout << p->data << " ";
        p = p->Next;
    }
    cout << p->data;
    cout << endl;
}

void InsertAtFirst(Node *&head, int value)
{
    Node *new_data = new Node(value);
    Node *current = head;
    if (head == NULL)
    {
        head = new_data;
        new_data->Next = new_data;
        return;
    }

    while (current->Next != head)
    {
        current = current->Next;
    }
    new_data->Next = head;
    current->Next = new_data;
    head = new_data;
}

void InsertAtLast(Node *&head, int value)
{
    Node *new_data = new Node(value);
    Node *p = head;

    if (head == NULL)
    {
        head = new_data;
        new_data->Next = new_data;
        return;
    }
    else
    {
        while (p->Next != head)
        {
            p = p->Next;
        }
        new_data->Next = p->Next;
        p->Next = new_data;
    }
}

void InsertAtPosition(Node *&head, int value, int position)
{
    Node *new_data = new Node(value);

    if (position == 1)
    {
        InsertAtFirst(head, value);
        return;
    }
    Node *p = head;
    int count = 1;

    while (count < position - 1)
    {
        p = p->Next;
        count++;
    }
    new_data->Next = p->Next;
    p->Next = new_data;
}

void DeleteATFirst(Node *&head)
{
    Node *p = head;
    Node *deleted = head;
    while (p->Next != head)
    {
        p = p->Next;
    }
    head = head->Next;
    p->Next = head;
    deleted->Next = NULL;
    delete deleted;
}

void DeleteATLast(Node *&head)
{
    Node *current = head;
    Node *N = head->Next;

    while (N->Next != head)
    {
        current = current->Next;
        N = N->Next;
    }
    current->Next = N->Next;
    delete (N);
}

void DeleteAtPosition(Node *&head, int position)
{
    Node *current = head;
    Node *N = head->Next;
    int count = 1;

    if (position == 1)
    {
        DeleteATFirst(head);
        return;
    }

    while (count < position - 1)
    {
        current = current->Next;
        N = N->Next;
        count++;
    }
    current->Next = N->Next;
    N->Next = NULL;
    delete N;
}

int main()
{
    // Node *head = NULL;
    Node *head = new Node(10);
    Node *second = new Node(20);
    head->Next = second;
    second->Next = head;
    print(head);
    InsertAtFirst(head, 30);
    print(head);
    InsertAtLast(head, 40);
    print(head);
    InsertAtPosition(head, 35, 5);
    print(head);
    DeleteATFirst(head);
    print(head);
    DeleteATLast(head);
    print(head);
    DeleteAtPosition(head, 1);
    print(head);
}