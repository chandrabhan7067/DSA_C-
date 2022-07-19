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

bool rootToLeafSum(Node *root, int s, int sum){
    if(!root)
        return false;

    sum += root->data;

    // if leaf Node then check if its path sum is equal to given sum

    if(root->left == NULL && root->right == NULL){
        if(sum == s){
            return true;
        }
        else{
            return false;
        }
    }

    bool left = rootToLeafSum(root->left,s,sum);
    bool right = rootToLeafSum(root->right,s,sum);
    return left || right;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int sum = 0, s = 4;
    cout<<rootToLeafSum(root,s,sum);
}