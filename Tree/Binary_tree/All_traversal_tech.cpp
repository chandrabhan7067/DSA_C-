#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *buildTree(Node *root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left child of :"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right child of :"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node *root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout<<"Inorder traversal"<<endl;
    inorder(root);

    cout<<endl<<"preorder traversal"<<endl;
    preorder(root);

    cout<<endl<<"postorder traversal"<<endl;
    postorder(root);
}