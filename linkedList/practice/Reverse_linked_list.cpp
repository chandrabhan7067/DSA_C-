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

void print(Node *head){
    Node *p = head;

    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

// Time and space complexity of recursive solution is  o(n)

// using recursion---------------------------------------------

Node* Reverse_recursion1(Node *head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *New_head = Reverse_recursion1(head->next);
    head->next->next = head;
    head->next = NULL;
    return New_head;
}

//using recursion--------------------------------------

// void Reverse_recursion(Node *&head, Node *curr, Node *pre){
//     if (curr == NULL)
//     {
//         head = pre;
//         return;
//     }
    
//     Node *forward = curr->next;
//     Reverse_recursion(head,forward,curr);
//     curr->next = pre;
// }

// void Reverse(Node *&head)
// {
//     Node *current = head;
//     Node *pre = NULL;
//     Reverse_recursion(head,current,pre);
// }

// --------------------------------------------------------

// Irative solution

// void Reverse(Node *&head)
// {
//     Node *current = head;
//     Node *pre = NULL;
//     Reverse_recursion(head,current,pre);
    // Node *forward = NULL;

    // while (current != NULL)
    // {
    //     forward = current->next;
    //     current->next = pre;
    //     pre = current;
    //     current = forward;
    // }
    // head = pre;
// }

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    head->next = second;
    second->next = third;
    third->next = NULL;

    print(head);
    // Reverse(head);
    // print(head);


//--- USING RECURSION-------------------------

    // Node *current = head;
    // Node *pre = NULL;
    // Reverse_recursion(head,current,pre);
    // print(head);

//--------------------------------------------
    head = Reverse_recursion1(head);
    print(head);

}