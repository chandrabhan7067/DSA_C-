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

void solve(Node *root, int level, int &ans, int &mx){
    if(root == NULL){
        return;
    }

    if(ans == 0){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        if(mx == -1){
            mx = level;
        }
        else{
            if(level != mx){
                ans = 0;
            }
        }
        return;
    }

    solve(root->left,level+1,ans,mx);
    solve(root->right,level+1,ans,mx);
}

int leafAtSameLevel(Node *root){
    int ans = 1;
    int mx = -1;
    int level = 1;
    solve(root,level,ans,mx);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<leafAtSameLevel(root);
}