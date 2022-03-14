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

Node *solve(Node *&head, int k)
{
    if (head == NULL || head->Next == NULL)
    {
        return head;
    }
    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->Next != NULL)
        {
            prev = temp;
            temp = temp->Next;
        }
        temp->Next = head;
        head = temp;
        prev->Next = NULL;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    // Node *fourth = new Node(4);
    // Node *fifth = new Node(5);
    head->Next = second;
    second->Next = third;
    // third->Next = fourth;
    // fourth->Next = fifth;
    // fifth->Next = NULL;
    third->Next = NULL;

    print(head);
    Node *ans = solve(head, 200);
    print(ans);
}