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

void print(Node *head){
    Node *ptr = head;

    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void sort(Node *&head){
    Node *temp = head;

    int zerocnt = 0;
    int onecnt = 0;
    int twocnt = 0;

    while(temp != NULL){
        if(temp->data == 0){
            zerocnt++;
        }
        else if(temp->data == 1){
            onecnt++;
        }
        else if(temp->data == 2){
            twocnt++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        if(zerocnt != 0){
            temp->data = 0;
            zerocnt--;
        }
        else if(onecnt != 0){
            temp->data = 1;
            onecnt--;
        }
        else if(twocnt != 0){
            temp->data = 2;
            twocnt--;
        }
        temp = temp->next;
    }
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