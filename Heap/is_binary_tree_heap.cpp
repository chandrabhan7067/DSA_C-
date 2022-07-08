#include<iostream>
using namespace std;

// time O(n)
// space O(n)

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

// count Node
int countNode(Node *root){
    if(root == NULL)
        return 0;

    int ans = 1 + countNode(root->left) + countNode(root->right);
}


// check for complete binary tree
bool CBT(Node *root, int i, int cnt){
    if(root == NULL){
        return true;
    }

    if(i > cnt)
        return false;

    else{
        bool left = CBT(root->left, 2*i+1,cnt);
        bool right = CBT(root->right, 2*i+2, cnt);
        return left && right;
    }
}

// check for Max heap

bool maxOrder(Node *root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL){
        return root->data > root->left->data;
    }

    else{
        bool left = maxOrder(root->left);
        bool right = maxOrder(root->right);
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }

}

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
    Node* root = NULL;
    root = buildTree(root);
    int index = 0;
    int cnt = countNode(root);

    if(CBT(root,index,cnt) && maxOrder(root)){
        cout<<"yes"<<endl;
        return true;
    }
    cout<<"no"<<endl;
    return false;
}