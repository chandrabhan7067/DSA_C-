#include <iostream>
#include <utility>
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

// pair including and excluding

pair<int,int>solve(Node *root){
    if(root == NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }

    pair<int,int>left = solve(root->left);
    pair<int,int>right = solve(root->right);

    pair<int,int>ans;

    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    return ans;
}

int maxSum(Node *root){
    pair<int,int>ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<maxSum(root);
}