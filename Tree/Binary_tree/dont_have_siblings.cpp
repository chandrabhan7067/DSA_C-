#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node *left = NULL;
        Node *right = NULL;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node * buildTree(Node *root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left child of: "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right child of: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void solve(Node *root, vector<int>&ans){
    if(root->left == NULL && root->right == NULL){
        return;
    }
    
    if(root->left != NULL && root->right == NULL){
        ans.push_back(root->left->data);
    }
    
    if(root->left == NULL && root->right != NULL){
        ans.push_back(root->right->data);
    }
    
    if(root->left){
        solve(root->left,ans);
    }
    
    if(root->right){
        solve(root->right,ans);
    }
    
}

vector<int> noSibling(Node* node)
{
    vector<int>ans;
    solve(node,ans);
    if(ans.empty()){
        ans.push_back(-1);
        return ans;
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = noSibling(root);

    for(auto i:ans){
        cout<<i<<" ";
    }
}