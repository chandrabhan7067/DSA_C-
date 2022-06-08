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

int main()
{
    Node *root = NULL;
    root = buildTree(root);
}