#include<iostream>
using namespace std;

// lowest common ancestor means closest root value for a and b both where a and b both are meat

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

int kthLargest(Node *root, int k, int &cnt){
    if(root == NULL){
        return -1;
    }

    int left = kthLargest(root->right,k, cnt);

    if(left != -1){
        return left;
    }

    cnt++;
    if(cnt == k){
        return root->data;
    }
    return kthLargest(root->left, k, cnt);
}

int check(Node *root, int k){
    int cnt = 0;
    return kthLargest(root, k, cnt);
}

int main()
{
    Node *root = NULL;
    cout<<"Enter input"<<endl;
    root = Takeinput(root);
    cout<<check(root,3);
}