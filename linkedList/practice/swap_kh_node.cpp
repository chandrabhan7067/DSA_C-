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

Node *swap(Node *head, int k, int n){
    if(k > n){
        return head;
    }

    Node *head1 = head;
    Node *pre1 = NULL;
    Node *head2 = head;
    Node *pre2 = NULL;

    for (int i = 1; i < k; i++)
    {
        pre1 = head1;
        head1 = head1->next;
    }

    for (int i = 1; i < n - k + 1; i++)
    {
        pre2 = head2;
        head2 = head2->next;
    }

    if(pre1 != NULL){
        pre1->next = head2;
    }
    if(pre2 != NULL){
        pre2->next = head1;
    }
    
    Node *temp = head2->next;
    head2->next = head1->next;
    head1->next = temp;

    if(k == 1){
        head = head2;
    }

    if(k == n){
        head = head1;
    }
    return head;
}

void print(Node *head)
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    int k = 1;
    int n = 4;

    Node *ans = swap(head,k,n);
    print(ans);


}