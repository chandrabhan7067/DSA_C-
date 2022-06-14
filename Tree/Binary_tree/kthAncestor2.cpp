#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter a data: " << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left child of :" << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right child of :" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void solve(Node *root,int node,int k,vector<int>path,int &ans){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    int size = path.size();

    if(path[size-1] == node){
        if(size - k - 1 >= 0){
            ans = path[size-k-1];
        }
        else{
            ans = -1;
        }
    }

    solve(root->left,node,k,path,ans);
    solve(root->right,node,k,path,ans);

    path.pop_back();

}

int kthAncestor(Node *root, int node, int k){
    int ans;
    vector<int>path;
    solve(root,node,k,path,ans);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int node = 4;
    int k = 2;
    cout<<kthAncestor(root,node,k);
}