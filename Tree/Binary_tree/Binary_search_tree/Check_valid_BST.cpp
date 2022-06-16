#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

// time O(n)
// space O(H)/ O(n)

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

Node *buildTree(Node *root, int value){
    if(root == NULL){
        root = new Node(value);
        return root;
    }

    if(root->data < value){
        root->right = buildTree(root->right, value);
    }
    else{
        root->left = buildTree(root->left, value);
    }
    return root;
}

Node *Takeinput(Node *root){
    int data;
    cin>>data;

    while(data != -1){
        root = buildTree(root,data);
        cin>>data;
    }
    return root;
}


bool isBST(Node *root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left = isBST(root->left, min,root->data);
        bool right = isBST(root->right, root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

bool checkBST(Node *root){
    return isBST(root,INT_MIN,INT_MAX);
}

int main()
{
    Node *root = NULL;
    cout<<"Enter data"<<endl;
    root = Takeinput(root);

    cout<<checkBST(root);

}