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

int val = 0;

void BSTtoGreater(Node *&root){

    if(!root){
        return;
    }

    BSTtoGreater(root->right);
    int temp = root->data;
    root->data = val;
    val += temp;
    BSTtoGreater(root->left);
}

void print(Node *root){
    if(!root)
        return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}


int main()
{
    Node *root = NULL;

    cout << "Enter the data for building the BST " << endl;
    takeInput(root);
    BSTtoGreater(root);
    print(root);
}