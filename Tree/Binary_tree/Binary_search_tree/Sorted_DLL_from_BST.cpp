#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = BuildBST(root->right, data);
    }

    else
    {
        root->left = BuildBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = BuildBST(root, data);
        cin >> data;
    }
}

void convertBSTtoSortedDLL(Node *root, Node *&head){
    if(root == NULL){
        return;
    }

    convertBSTtoSortedDLL(root->right,head);

    root->right = head;

    if(head != NULL){
        head->left = root;
    }

    head = root;

    convertBSTtoSortedDLL(root->left,head);
}

int main()
{
    Node *root = NULL;
    cout<<"Enter data"<<endl;
    takeInput(root);

    Node *head = NULL;

    convertBSTtoSortedDLL(root,head);
    // cout<<head->left->data;
    cout<<head->right->data;
}