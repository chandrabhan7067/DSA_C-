#include <iostream>
using namespace std;

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

void print(Node *&first)
{
    Node *ptr = first;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void insert(Node *&head, int value)
{
    Node *data = new Node(value);
    data->next = head;
    head = data;
}

Node *reverse(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *forword = curr->next;
    Node *prev = NULL;

    while (curr != NULL)
    {
        forword = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forword;
    }
    return prev;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    first->next = second;
    second->next = NULL;
    insert(first, 30);
    print(first);
    first = reverse(first);
    cout << endl<< "After reverse a linkedlist " << endl;
    print(first);
}