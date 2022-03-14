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

Node *Solve(Node *head)
{
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *temp = head;

    // first step copy list with next pointer
    while (temp != NULL)
    {
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // second step map all Node

    map<Node *, Node *> mapping;

    Node *orignalNode = head;
    Node *cloneNode = clonehead;

    while (orignalNode != NULL)
    {
        mapping[orignalNode] = cloneNode;
        cloneNode = clonehead->next;
        orignalNode = orignalNode->next;
    }

// connect random pointer

    orignalNode = head;
    cloneNode = clonehead;

    while (orignalNode != NULL)
    {
        clonehead->random = mapping[orignalNode->random];
        orignalNode = orignalNode->next;
        cloneNode = cloneNode->next;
    }
    return clonehead;
}