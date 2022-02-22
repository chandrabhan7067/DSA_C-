#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *Next;

    Node(int data)
    {
        this->data = data;
        this->Next = NULL;
    }
};

void print(Node *&head)
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->Next;
    }
    cout << endl;
}

void InsertAtFirst(Node *&head, int value)
{
    Node *p = new Node(value);
    p->Next = head;
    head = p;
}

void InsertAtLast(Node *&head, int value)
{
    Node *new_data = new Node(value);
    Node *p = head;

    while (p->Next != NULL)
    {
        p = p->Next;
    }
    new_data->Next = p->Next;
    p->Next = new_data;
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
    head = head->Next;
    p->Next = NULL;
    delete p;
}

void DeleteATLast(Node *&head)
{
    Node *current = head;
    Node *N = head->Next;

    while (N->Next != NULL)
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
    Node *head = new Node(10);
    Node *second = new Node(20);
    head->Next = second;
    second->Next = NULL;
    cout << "Before" << endl;
    print(head);
    cout << "After all insertion" << endl;
    InsertAtFirst(head, 5);
    InsertAtLast(head, 6);
    InsertAtPosition(head, 50, 1);
    print(head);
    cout << "After all deletion" << endl;
    DeleteATFirst(head);
    print(head);
    DeleteATLast(head);
    print(head);
    DeleteAtPosition(head, 3);
    print(head);
}