#include <iostream>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

int main()
{
    LinkedList *head = new LinkedList(10);
    LinkedList *second = new LinkedList(40);
    LinkedList *third = new LinkedList(30);

    head->next = second;
    second->next = third;
    third->next = NULL;
    cout<<third->data;
}