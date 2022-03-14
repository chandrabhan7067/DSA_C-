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

Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            temp = first;
            first = first->next;
        }

        else
        {
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    while (first != NULL)
    {
        temp->next = first;
        temp = first;
        first = first->next;
    }

    while (second != NULL)
    {
        temp->next = second;
        temp = second;
        second = second->next;
    }
    ans = ans->next;
    return ans;
}

Node *solve(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findmid(head);
    Node *first = head;
    Node *second = mid->next;
    mid->next = NULL;

    first = solve(first);
    second = solve(second);
    Node *ans = merge(first, second);
    return ans;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(11);
    Node *third = new Node(9);
    Node *fourth = new Node(7);
    Node *fifth = new Node(15);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    print(head);
    cout << endl;
    Node *ans = solve(head);
    print(ans);
}