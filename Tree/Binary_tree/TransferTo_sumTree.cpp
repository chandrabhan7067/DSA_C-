#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left = NULL;
        Node *right = NULL;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node * buildTree(Node *root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left child of: "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right child of: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node *root){
    if(!root)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int transferToSumTree(Node *&root){
    if(!root)
        return 0;

    int left = transferToSumTree(root->left);
    int right = transferToSumTree(root->right);
    int temp = root->data;
    root->data = left + right;
    return left + right + temp;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    transferToSumTree(root);
    inorder(root);
}