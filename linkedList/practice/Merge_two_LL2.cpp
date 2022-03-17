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
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *Solve(Node *&first, Node *&second)
{
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node *ptr = first;

    if (first->data > second->data)
    {
        ptr = second;
        second = second->next;
    }
    else
    {
        first = first->next;
    }

    Node *curr = ptr;

    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            curr->next = first;
            first = first->next;
        }
        else
        {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    if(first != NULL)
    {
        curr->next = first;
        // first = first->next;
    }
    else{
        curr->next = second;
    }

    // while (second != NULL)
    // {
    //     curr->next = second;
    //     second = second->next;
    // }
    
    return ptr;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(4);

    Node *head1 = new Node(2);
    Node *second1 = new Node(3);
    Node *third1 = new Node(4);

    head->next = second;
    second->next = third;
    third->next = NULL;

    head1->next = second1;
    second1->next = third1;
    third1->next = NULL;

    Node *ans = Solve(head, head1);
    print(ans);
}