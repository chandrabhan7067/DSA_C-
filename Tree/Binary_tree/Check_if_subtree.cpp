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

bool checkSame(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data == root2->data){
        bool left = checkSame(root1->left, root2->left);
        bool right = checkSame(root1->right, root2->right);
        return left && right;
    }
    return false;
}

bool isSubtree(Node *root1, Node *root2){
    if(root1 == NULL){
        return false;
    }

    if(root2 == NULL){
        return true;
    }

    if(checkSame(root1, root2)){
        return true;
    }

    bool left = isSubtree(root1->left,root2);
    bool right = isSubtree(root1->right,root2);
    return left || right;
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    root1 = buildTree(root1);
    cout<<"Again Enter data"<<endl;
    root2 = buildTree(root2);
    cout<<isSubtree(root1,root2);
}