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


void search(Node *root, int s, int &ans){
    if(!root)
        return;

    if(root->data == s){
        cout<<"mil gya"<<endl;
        ans = root->data;
        return;
    }

    if(root->data > s){
        cout<<"Left call"<<endl;
        ans = root->data;
        search(root->left,s,ans);
    }
    
    else{
        cout<<"right call"<<endl;
        search(root->right,s,ans);
    }
}

int solve(Node *root,int s){
    if(!root){
        return -1;
    }

    int ans = -1;
    search(root,s,ans);
    return ans;
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data for building the BST " << endl;
    takeInput(root);

    int s = 4;
    cout<<solve(root,s);
}