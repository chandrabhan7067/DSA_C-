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

void print(Node *head)
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->Next;
    }
    cout << endl;
}

void InsertTail(Node *&head, Node *&tail, int value)
{
    Node *new_val = new Node(value);
    if (head == NULL)
    {
        head = new_val;
        tail = new_val;
        return;
    }
    else
    {
        tail->Next = new_val;
        tail = new_val;
    }
}

void inser(Node *&tail, Node *curr)
{
    tail->Next = curr;
    tail = curr;
}

Node *solve(Node *&head, int value)
{
    if (head == NULL || head->Next == NULL)
    {
        return head;
    }

    Node *LessH = new Node(-1);
    Node *LessT = LessH;
    Node *greaterH = new Node(-1);
    Node *greaterT = greaterH;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data < value)
        {
            inser(LessT, temp);
        }
        else
        {
            inser(greaterT, temp);
        }
        temp = temp->Next;
    }

    LessT->Next = greaterH->Next;
    greaterT->Next = NULL;

    print(LessH->Next);
    return LessH->Next;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(4);
    Node *third = new Node(3);
    Node *fourth = new Node(2);
    Node *fifth = new Node(5);
    Node *six = new Node(2);
    head->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = fifth;
    fifth->Next = six;
    six->Next = NULL;
    // print(head);
    cout << endl;
    Node *N = solve(head, 3);
    print(N);
}