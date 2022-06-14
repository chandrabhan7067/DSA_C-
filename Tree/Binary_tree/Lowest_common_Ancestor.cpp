#include <iostream>
#include <utility>
using namespace std;

// time O(n)
// space O(height of tree)

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter a data: " << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left child of :" << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right child of :" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

Node *lca(Node *root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node *leftAns = lca(root->left,n1,n2);
    Node *rightAns = lca(root->right,n1,n2);

    if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }

    if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    Node *ans = lca(root,3,4);
    cout<<ans->data;
}