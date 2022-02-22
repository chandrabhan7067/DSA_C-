#include <iostream>
using namespace std;

class linkedlist
{

public:
    int data;
    linkedlist *n;

    linkedlist(int data)
    {
        this->data = data;
        this->n = NULL;
    }
};

int main()
{
    linkedlist *head = new linkedlist(10);
    cout << head->data << endl;
}