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

Node *delete_Nth(Node *head, int n)
{
    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    if (n > cnt)
    {
        return head;
    }

    else if (n == cnt)
    {
        return head->next;
    }

    else
    {
        Node *curr = head;
        Node *pre = NULL;

        for (int i = 0; i < cnt - n; i++)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        return head;
    }
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);
    cout << endl;
    Node *ans = delete_Nth(head, 2);
    print(ans);
}