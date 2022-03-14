#include <iostream>
using namespace std;

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

void insert(Node *&Tail, Node *curr)
{
    Tail->next = curr;
    Tail = curr;
}

void print(Node *head){
    Node *ptr = head;

    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void sort(Node *&head)
{
    Node *zeroHead = new Node(-1);
 	Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    
    Node *curr = head;
    
    while(curr != NULL){
        int value = curr->data;
        
        if(value == 0){
            insert(zeroTail,curr);
        }
        
        else if(value == 1){
            insert(oneTail,curr);
        }
        
        else if(value == 2){
            insert(twoTail, curr);
        }
        curr = curr->next;
    }
    
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    
    head = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(0);
    Node *third = new Node(2);
    Node *fourth = new Node(1);
    Node *fifth = new Node(2);
    Node *sixth = new Node(-1);

// 1 0 2 1 2 -1

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next  = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    print(head);
    sort(head);
    print(head);
}