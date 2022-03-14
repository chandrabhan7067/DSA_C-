#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *random;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

void insertAtTail(Node *head, Node *tail, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *SOlve(Node *head)
{
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // connect list
    Node *cloneNode = clonehead;
    Node *orignalNode = head;

    while (orignalNode != NULL)
    {
        Node *next = orignalNode->next;
        orignalNode->next = cloneNode;
        orignalNode = next;

        next = cloneNode->next;
        cloneNode->next = orignalNode;
        clonehead = next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            if (temp->random != NULL)
            {
                temp->next->random = temp->random->next;
            }
            else
            {
                temp->next->random = temp->random;
            }
        }
        temp = temp->next->next;
    }

    orignalNode = head;
    cloneNode = clonehead;

    while (orignalNode != NULL)
    {
        orignalNode->next = cloneNode->next;
        orignalNode = orignalNode->next;

        if (orignalNode != NULL)
        {
            cloneNode->next = orignalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    return clonehead;
}

int main()
{
    
}