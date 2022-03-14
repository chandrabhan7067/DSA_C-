#include <iostream>
#include <map>
using namespace std;

// Time complexity is   O(n)
// space complexity is   O(n)

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

void insert(Node *&head, int data)
{
    Node *ptr = new Node(data);
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    ptr->next = head;
    head = ptr;
}

void print(Node *head)
{
    Node *ptr = head;

    while (head != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

bool Is_loop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *node1 = new Node(10);
    Node *tail = node1;
    Node *head = node1;

    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    // tail->next = head->next;
    // cout << "head is:" << head->data << endl;
    // cout << "Tail is:" << tail->data << endl;
    // print(head);

    if (Is_loop(head))
    {
        cout << "Loop is present";
    }
    else
    {
        cout << "Loop is not present";
    }
}