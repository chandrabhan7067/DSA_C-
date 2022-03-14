#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pre;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->pre = NULL;
    }
};

void print(Node *head)
{
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data<<" ";
        ptr = ptr->next;
    }
}

Node* reverse(Node *&head){
    if(head == NULL && head->next == NULL){
        return head;
    }

    Node *pre = NULL;
    Node *forward = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = pre;
        curr->pre = curr->next;
        pre = curr;
        curr = forward;
    }
    return pre;
}

int main()
{
    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(30);

    head->next = first;
    head->pre = NULL;

    first->next = second;
    first->pre = head;

    second->next = NULL;
    second->pre = first;

    print(head);
    cout<<endl;
    head = reverse(head);
    print(head);
}