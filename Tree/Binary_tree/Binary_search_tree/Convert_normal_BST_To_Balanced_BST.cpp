#include <iostream>
#include <queue>
using namespace std;

//Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.
// time O(n)
// space O(n)

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

void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

Node *MakeToList(vector<int>inorderVal, int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s + e)/2;
    Node *root = new Node(inorderVal[mid]);
    root->left = MakeToList(inorderVal,s,mid-1);
    root->right = MakeToList(inorderVal,mid+1,e);
    return root;
}

Node *convertToList(Node *root){
    vector<int>ans;
    inorder(root,ans);
    return MakeToList(ans,0,ans.size()-1);
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data for building the BST " << endl;
    takeInput(root);
}