#include <iostream>
#include <queue>
#include<limits.h>
using namespace std;

//Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *preOrderTree(vector<int>&preorder,int min, int max, int &i){
    if(i >= preorder.size()){
        return NULL;
    }

    if(preorder[i] < min || preorder[i] > max){
        return NULL;
    }

    Node *root = new Node(preorder[i]);
    i++;
    root->left = preOrderTree(preorder,min,root->data,i);
    root->right = preOrderTree(preorder,root->data,max,i);
    return root;
}

int main()
{
    vector<int>preorder{10, 5, 1, 7, 40, 50};
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    cout<<preOrderTree(preorder,min,max,i)->left->data;
}