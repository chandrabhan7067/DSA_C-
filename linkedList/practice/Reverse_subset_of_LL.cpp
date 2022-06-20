#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node *Reverse(Node *head, int m, int n){
    if(head == NULL || head -> next == NULL || m == n){
        return NULL;
    }

    // step 1 move curr to correct position
    Node *curr = head;
    Node *currPre = NULL;
    
    for(int i = 1; i < m; i++){
        currPre = curr;
        curr = curr -> next;
    }

    Node *temp = curr;
// step 2 reverse the list
    Node *pre = NULL;
    Node *forward = NULL;
    
    while(m <= n && curr != NULL){
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
        m++;
    }
    
// if currPre == null mean our tast is to reverse list from head
    if(currPre == NULL){
        head -> next = curr;
        head = pre;
        return head;
    }
    
// else our lask is to reverse list after the head
    else{
        currPre -> next = pre;
        temp -> next = curr;
        return head;
    }
}

void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
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

    Node *root = Reverse(head,2,4);
    print(root);
}