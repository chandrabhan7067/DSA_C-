#include <iostream>
#include <queue>
using namespace std;

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

void inorder(Node *root, vector<int>&inorderVal){
    if(root == NULL){
        return;
    }

    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}

Node *makeBST(vector<int>sortedArray, int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s + e) / 2;
    Node *root = new Node(sortedArray[mid]);
    root->left = makeBST(sortedArray, s, mid - 1);
    root->right = makeBST(sortedArray, mid+1, e);
    return root;
}

int main()
{
    Node *root = NULL;
    cout<<"Enter data"<<endl;
    takeInput(root);
    vector<int>inorderVal;
    inorder(root,inorderVal);
    vector<int>sorted;

    int sum = 0;
    for (int i = 0; i < inorderVal.size(); i++)
    {
        sum += inorderVal[i];
    }

    sorted.push_back(sum);

    for (int i = 0; i < inorderVal.size()-1; i++)
    {
        sum = sum - inorderVal[i];
        sorted.push_back(sum);
    }

    cout<<makeBST(sorted,0,sorted.size()-1)->data;
    
}

