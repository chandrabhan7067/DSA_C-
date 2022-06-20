#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

// time O(n)
// space O(H)

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

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

Node *buildTree(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return root;
    }

    if (root->data <= value)
    {
        root->right = buildTree(root->right, value);
    }
    else
    {
        root->left = buildTree(root->left, value);
    }
    return root;
}

Node *Takeinput(Node *root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = buildTree(root, data);
        cin >> data;
    }
    return root;
}

info longestBST(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = longestBST(root->left, ans);
    info right = longestBST(root->right, ans);

    info currNode;

    currNode.maxi = max(right.maxi, root->data);
    currNode.mini = min(left.mini, root->data);
    currNode.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini)
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data" << endl;
    root = Takeinput(root);
    int ans = 0;
    info temp = longestBST(root, ans);
    cout << ans;
}