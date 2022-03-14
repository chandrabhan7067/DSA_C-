#include <iostream>
#include <map>
using namespace std;

// Here we are removing duplicate element in a unsorted linkedlist using o(n^2) time complexity

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
    Node *curr, *pre, *temp;
    if (head == NULL)
    {
        return;
    }
    curr = head;

    while (curr != NULL)
    {
        pre = curr;
        temp = curr->Next;

        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                pre->Next = temp->Next;
                Node *deleted = temp;
                delete (deleted);
                temp = pre->Next;
            }
            else
            {
                temp = temp->Next;
                pre = pre->Next;
            }
        }
        curr = curr->Next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    head->Next = second;
    second->Next = NULL;
    InsertAtFirst(head, 30);
    InsertAtFirst(head, 40);
    InsertAtFirst(head, 10);
    InsertAtFirst(head, 60);
    print(head);
    Remove(head);
    print(head);
}