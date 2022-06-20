#include <iostream>
#include <vector>
#include<bits/stdc++.h>
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

void CountNodeLieInRange(Node *root,int l, int h, vector<int>&ans){
    if(root == NULL){
        return;
    }

    if(root->data >= l && root->data < h){
        ans.push_back(root->data);
    }

    if(root->left){
        CountNodeLieInRange(root->left, l, h, ans);
    }

    if(root->right){
        CountNodeLieInRange(root->right, l, h, ans);
    }
}

//        16
//      /    \
//     7     20
//   /   \
//  1    10
// l = 13, h = 23

int main()
{
    Node *root = NULL;
    takeInput(root);
    vector<int>ans;
    int l = 13, h = 23;
    CountNodeLieInRange(root, l, h, ans);
    sort(ans.begin(), ans.end());

    for(auto i:ans){
        cout<<i<<" ";
    }
}