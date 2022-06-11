#include <iostream>
#include <vector>
using namespace std;

// time complexity is   O(n)
// space complexity is O(height of tree)

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

void solve(Node *root,vector<int>&ans,int cnt){
    if(root == NULL){
        return;
    }

    if(cnt == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right,ans,cnt+1);
    solve(root->left,ans,cnt+1);
}

vector<int>rightView(Node *root){
    vector<int>ans;
    int cnt = 0;
    solve(root,ans,cnt);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = rightView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}