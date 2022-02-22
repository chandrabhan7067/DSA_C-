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

void print(Node *&head){
    Node *ptr = head;

    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

void Sort_linked_list(Node *&head){
    Node*ptr = head;

    while(ptr != NULL){
    Node *mini = ptr;

    }

}

int main()
{
    Node *head = new Node(30);
    Node *second = new Node(20);
    Node *third = new Node(10);

    head->next = second;
    second->next = third;
    third->next = NULL;

    print(head);
}