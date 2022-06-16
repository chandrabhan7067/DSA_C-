#include<iostream>
#include<limits.h>
#include<queue>
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

Node* LCA(Node *root, int a, int b){
    if(root == NULL){
        return NULL;
    }

    if(root->data < a && root->data < b){
        return LCA(root->right, a, b);
    }
    if(root->data > a && root->data > b){
        return LCA(root->left, a, b);
    }
    return root;
}

// Itratively 
// space O(1)

Node* LCA2(Node *root, int a, int b){
  while(root != NULL){
       
      if(root->data < a && root -> data < b)
            root = root -> right;
       
      else if(root->data > a && root -> data > b)
            root = root -> left;
       
      else{
          return root;
      }
    }
}

int main()
{
    Node *root = NULL;
    cout<<"Enter data"<<endl;
    root = Takeinput(root);
    cout<<LCA(root,1,3)->data;

}