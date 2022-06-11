#include <iostream>
#include <utility>
using namespace std;

class Node{
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

pair<bool,int>sumTree(Node *root){
    if(root == NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int>left = sumTree(root->left);
    pair<bool,int>right = sumTree(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool condition = root->data == (left.second + right.second);

    pair<bool,int>ans;

    if(leftAns && rightAns && condition){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<sumTree(root).first;
}