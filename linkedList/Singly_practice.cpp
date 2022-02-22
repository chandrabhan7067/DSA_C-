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

    // void print(Node *head){
    //     Node *ptr = head;

    //     while (ptr != NULL)
    //     {
    //         cout<<ptr->data<<" ";
    //         ptr = ptr->next;
    //     }
    //     cout<<endl;
    // }

    // Node* InsertAtBegin(Node *head, int value){
    //     Node *new_data = new Node(value);
    //     // new_data->data = value;
    //     new_data->next = head;
    //     return new_data;
    // }


 
};

void print(Node *head){
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

// Node* InsertAtBegin(Node *head, int value){
//     Node *new_data = new Node(value);
//     new_data->next = head;
//     return new_data;
// }

void InsertAtBegin(Node *&head, int value){
    Node *new_data = new Node(value);
    new_data->next = head;
    head = new_data;
}

void InsertAtEnd(Node *&head,int value){
    Node *new_data = new Node(value);
    Node* ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_data->next = ptr->next;
    ptr->next = new_data;
}

void InsertAtPosition(Node *&head,int position,int value){
    Node *new_data = new Node(value);
    Node *ptr = head;
    int count = 1;

    if (position == 1)
    {
        InsertAtBegin(head,value);
        return;
    }
    

    while (count < position - 1)
    {
        ptr = ptr->next;
        count++;
    }
    new_data->next = ptr->next;
    ptr->next = new_data;

}

void DeleteNode(Node *&head, int position){
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    else{
        Node* curr = head;
        Node* N = head->next;
        int count = 1;

        while (count < position - 1)
        {
            curr = curr->next;
            N = N->next;
            count++;
        }
        curr->next = N->next;
        N->next = NULL;
        delete N;
    }
    
}

int main()
{
    Node *p = new Node(10);
    Node *p1 = new Node(100);
    p->next = p1;
    p1->next = NULL;
    
    // Node *head = p;
    // p->print(p);
    print(p);
    // p = p->InsertAtBegin(p,20);          // This is used when we pase our head pas by value
    // p = InsertAtBegin(p,20);          // This is used when we pase our head pas by value
    // p->InsertAtBegin(p,30);

    InsertAtBegin(p,20);
    InsertAtBegin(p,30);
    InsertAtEnd(p,50);
    // InsertAtPosition(p,1,5);
    // InsertAtPosition(p,7,15);
    print(p);

    DeleteNode(p,1);
    print(p);
    // cout << p->data;
}