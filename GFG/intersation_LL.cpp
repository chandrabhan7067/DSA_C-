#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int value){
            this->data = value;
            this->next = NULL;
        }
};

void print(Node *LL){
    Node *temp = LL;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

// Node *Intersation(Node *L1, Node )

int main(){
    Node *first = new Node(10);
    Node *second = new Node(20);

    first->next = second;
    second->next = NULL;
    print(first);
}