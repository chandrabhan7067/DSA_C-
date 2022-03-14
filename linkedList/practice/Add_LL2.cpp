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

void InsertTail(Node *&head, Node *&Tail, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        Tail = temp;
        return;
    }

    else
    {
        Tail->next = temp;
        Tail = temp;
    }
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *add(Node *head1, Node *head2)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        int sum = head1->data + head2->data + carry;
        int digit = sum % 10;
        InsertTail(ansHead, ansTail, digit);

        carry = sum / 10;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        int sum = head1->data + carry;
        int digit = sum % 10;
        InsertTail(ansHead, ansTail, digit);

        carry = sum / 10;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        int sum = head2->data + carry;
        int digit = sum % 10;
        InsertTail(ansHead, ansTail, digit);

        carry = sum / 10;
        head1 = head2->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        InsertTail(ansHead, ansTail, digit);

        carry = sum / 10;
    }
    return ansHead;
}

void print(Node *head)
{
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Node *head1 = new Node(4);
    Node *second = new Node(3);
    Node *third = new Node(2);
    head1->next = second;
    second->next = third;
    third->next = NULL;

    Node *head2 = new Node(5);
    Node *second2 = new Node(5);
    head2->next = second2;
    second2->next = NULL;

    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *ans = add(head1, head2);
    ans = reverse(ans);
    print(ans);
}