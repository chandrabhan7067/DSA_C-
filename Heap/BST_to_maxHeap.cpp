#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
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


void inorder_traversal(Node *root, vector<int>&inorder){
    if(root == NULL){
        return;
    }

    inorder_traversal(root->left,inorder);
    inorder.push_back(root->data);
    inorder_traversal(root->right,inorder);
}

void BSTtoMaxHeap(Node *&root, vector<int>&inorder, int& index){
    if(root == NULL){
        return;
    }

    BSTtoMaxHeap(root->left,inorder,index);
    BSTtoMaxHeap(root->right,inorder,index);
    root->data = inorder[index];
    index++;
}

int main()
{
    Node *root = NULL;
    takeInput(root);
    vector<int>inorder;
    inorder_traversal(root,inorder);
    int index = 0;
    BSTtoMaxHeap(root,inorder,index);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data;
}

// BST

        //          4
        //        /   \
        //       2     6
        //     /  \   /  \
        //    1   3  5    7  

// max heap

        //        7
        //      /   \
        //     3     6
        //   /   \  /   \
        //  1    2 4     5