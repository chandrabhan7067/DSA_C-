#include <iostream>
#include<utility>
using namespace std;

// the tree is balanced if difference between height of left subtree ans height of right subtree is not greater than 1 for all nodes

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

int height(Node *root){
    if(root == NULL){
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    int ans = max(leftH,rightH) + 1;

    return ans;

}


// second approach 
// time complexity   O(n)
// space O(height of tree)

pair<bool,int>balanced_fast(Node *root){
    if(root == NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    pair<bool,int>left = balanced_fast(root->left);
    pair<bool,int>right = balanced_fast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = (left.second - right.second) <= 1;

    pair<bool,int>ans;
    ans.second = max(left.first, right.first) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
        return ans;
    }
    else{
        ans.first = false;
        return ans;
    }
}

// time O(n^2)
// space O(height of tree)

bool balanced(Node *root){
    if(root == NULL){
        return true;
    }

    bool left  = balanced(root->left);
    bool right = balanced(root->right);

    bool diff = (height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }

}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<balanced_fast(root).first;
}