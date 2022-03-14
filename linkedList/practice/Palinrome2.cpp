#include <iostream>
using namespace std;

// Time complexity is  O(n)
// space complexity is  O(1)

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

Node *mid(Node *head)
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

Node *Reverse(Node *head)
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

bool check(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

//find middle
    Node *middle = mid(head);

// reverse list after middle
    Node *temp = middle->next;
    middle->next = Reverse(temp);

// compare both half
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

// repeat for make list as previous
    temp = middle->next;
    middle->next = Reverse(temp);

    return true;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(1);

    head->next = second;
    second->next = third;
    third->next = NULL;

    if (check(head))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}