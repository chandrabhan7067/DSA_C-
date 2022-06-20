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

int solve(Node *root, int &ans, int k){
    if(root == NULL){
        return ans;
    }

    if(ans >= abs(root->data - k)){
        ans = abs(root->data - k);
    }

    if(root->data > k){
        solve(root->left, ans, k);
    }

    else if(root->data < k){
        solve(root->right, ans, k);
    }
    else{
        return 0;
    }

}

int closestEle(Node *root, int k){
    int ans = k;
    return solve(root,ans,k);
}

int main()
{
    Node *root = NULL;
    takeInput(root);
    cout<<closestEle(root,13);

}