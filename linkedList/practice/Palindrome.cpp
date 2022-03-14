#include <iostream>
#include <vector>
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

bool palindrome(vector<int> n)
{
    int len = n.size();
    int s = 0;
    int e = len - 1;

    while (s <= e)
    {
        if (n[s] != n[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool check(Node *head)
{
    Node *temp = head;
    vector<int> n;

    while (temp != NULL)
    {
        n.push_back(temp->data);
        temp = temp->next;
    }
    return palindrome(n);
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;
    third->next = NULL;

    if (check(head))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}