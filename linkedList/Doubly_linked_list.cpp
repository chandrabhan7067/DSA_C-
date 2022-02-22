#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
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

void InsertAtFirst(Node *&head, int value)
{
    Node *new_data = new Node(value);

    if (head == NULL)
    {
        new_data->next = head;
        head = new_data;
    }
    else
    {
        new_data->next = head;
        head->prev = new_data;
        head = new_data;
    }
}

void InsertAtLast(Node *&head, int value)
{
    Node *new_data = new Node(value);

    if (head == NULL)
    {
        head = new_data;
        return;
    }

    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        new_data->next = p->next;
        p->next = new_data;
        new_data->prev = p;
    }
}

void InsertAtPosition(Node *&head, int value, int position)
{
    Node *new_data = new Node(value);
    Node *p = head;
    int count = 1;

    if (position == 1)
    {
        InsertAtFirst(head, value);
        return;
    }

    while (count < position - 1)
    {
        p = p->next;
        count++;
    }
    new_data->next = p->next;
    new_data->prev = p;
    p->next = new_data;
}

void DeleteAtFirst(Node *&head)
{
    Node *p = head;
    head = head->next;
    p->next = NULL;
    head->prev = NULL;
    delete p;
}

void DeleteAtLast(Node *&head)
{
    Node *current = head;
    Node *N = head->next;
    while (N->next != NULL)
    {
        current = current->next;
        N = N->next;
    }
    current->next = N->next;
    N->prev = NULL;
    delete N;
}

void DeleteAtPosition(Node *&head, int position)
{

    if (position == 1)
    {
        DeleteAtFirst(head);
    }

    Node *current = head;
    Node *N = head->next;
    int count = 1;
    while (count < position - 1)
    {
        current = current->next;
        N = N->next;
        count++;
    }
    current->next = N->next;
    delete N;
}

int main()
{
    // Node *head = NULL;
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    // print(head);
    // InsertAtFirst(head, 5);
    // print(head);
    // InsertAtLast(head, 40);
    // print(head);
    // InsertAtPosition(head, 35, 1);
    // print(head);
    DeleteAtFirst(head);
    // print(head);
    // DeleteAtLast(head);
    // print(head);
    // DeleteAtPosition(head, 1);
    print(head);
}