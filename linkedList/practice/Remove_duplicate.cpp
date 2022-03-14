#include <iostream>
#include <map>
using namespace std;

// Here we are removing duplicate element in a unsorted linkedlist using map
// time complexity is O(n)
// space complexity is O(n)

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
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

void InsertAtFirst(Node *&head, int value)
{
    Node *p = new Node(value);
    p->next = head;
    head = p;
}

void removeDuplicates(Node *head)
{
    map<int, bool> visited;
    Node *prev = head;
    Node *curr = head->next;

    visited[prev->data] = true;

    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            visited[curr->data] = true;
            prev = prev->next;
        }
        curr = prev->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    head->next = second;
    second->next = NULL;
    InsertAtFirst(head, 30);
    InsertAtFirst(head, 40);
    InsertAtFirst(head, 10);
    InsertAtFirst(head, 60);
    print(head);
    removeDuplicates(head);
    print(head);
}