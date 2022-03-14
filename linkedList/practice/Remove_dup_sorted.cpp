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

void Remove(Node *&head)
{
    if(head == NULL){
        return;
    }

    Node *curr = head;

    while (curr->Next != NULL)
    {
        if (curr->data == curr->Next->data)
        {
            Node *next_next = curr->Next->Next;
            delete(curr->Next);
            curr->Next = next_next;

            // Another way
            // curr->Next = curr->Next->Next;
        }
        curr = curr->Next;
    }
}

int main()
{
    Node *head = new Node(50);
    Node *second = new Node(60);
    head->Next = second;
    second->Next = NULL;
    InsertAtFirst(head, 50);
    InsertAtFirst(head, 40);
    InsertAtFirst(head, 30);
    InsertAtFirst(head, 20);
    print(head);
    Remove(head);
    print(head);
}