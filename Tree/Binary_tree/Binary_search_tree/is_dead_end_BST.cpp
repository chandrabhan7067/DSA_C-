#include <iostream>
#include <limits.h>
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

// Here Dead End means, we are not able to insert any element after that node.

bool isDeadEnd(Node *root, int min, int max){
    if(root == NULL){
        return false;
    }

    if((max - min) <= 2){
        return true;
    }

    bool left = isDeadEnd(root->left, min, root->data);
    bool right = isDeadEnd(root->right, root->data, max);
    return left || right;
}

int main()
{
    Node *root = NULL;
    takeInput(root);
    cout<<isDeadEnd(root,0,INT_MAX);
}