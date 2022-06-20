#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;

// arr[]  = {40,30,35,80,100}
// Output: 35 30 100 80 40

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

Node *buildTree(int *preorder, int min, int max, int &i, int n){
    if(i >= n){
        return NULL;
    }

    if(preorder[i] < min || preorder[i] > max){
        return NULL;
    }

    Node *root = new Node(preorder[i]);
    i++;
    root->left = buildTree(preorder, min, root->data, i, n);
    root->right = buildTree(preorder, root->data, max, i, n);
    return root;
}

int main()
{
    int pre[] = {40, 30, 35, 80, 100};
    int n =5;
    int i = 0;
    Node *preNode = buildTree(pre, INT_MIN, INT_MAX, i, n);
    cout<<preNode->left->data<<" ";
    cout<<preNode->right->data;
}
