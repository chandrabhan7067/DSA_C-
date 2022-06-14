#include <iostream>
#include <vector>
using namespace std;

// time O(n)
// space O(height of tree)

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

void solve(Node *root, int k, int &cnt, vector<int>path){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    solve(root->left,k,cnt,path);
    solve(root->right,k,cnt,path);

    int size = path.size();
    int sum = 0;

    for (int i = size-1; i >= 0; i--)
    {
        sum += path[i];
        if(sum == k){
            cnt++;
        }
    }
    path.pop_back();
}

int k_sum(Node *root,int k){
    int cnt = 0;
    vector<int>path;
    solve(root,k,cnt,path);
    return cnt;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<k_sum(root,3);
}