#include <iostream>
using namespace std;

// Time complexity is   O(n)
// space complexity is   O(1)

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
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void Insertion(Node *&head, int value)
{
    Node *ptr = new Node(value);
    if (head == NULL)
    {
        head = ptr;
        return;
    }

    ptr->next = head;
    head = ptr;
}

Node *NodeInLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

// This function is return that node Which is staring node in the loop

Node *first_Node(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *fast = NodeInLoop(head);
    Node *slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void Delete_loop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *start_node = first_Node(head);
    Node *temp = start_node->next;

    while (temp->next != start_node)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    Insertion(head, 20);
    Insertion(head, 30);
    Insertion(head, 40);
    Insertion(head, 50);
    tail->next = head->next;
    Node *ans = first_Node(head);
    cout << "Beginning Node of the loop is: " << ans->data;
    Delete_loop(head);
    cout << endl;
    print(head);
}