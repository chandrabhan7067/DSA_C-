#include <iostream>
#include <limits.h>
using namespace std;

// time    O(n)
// space   O(Height of tree)

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data :" << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left child of: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right child of: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int maxPath(Node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int leftSum = maxPath(root->left, res);
    int rightSum = maxPath(root->right, res);

    if (root->left && root->right)
    {
        res = max(res, root->data + leftSum + rightSum);
        return root->data + max(leftSum, rightSum);
    }

    if (!root->left)
    {
        return rightSum + root->data;
    }

    else
    {
        return root->data + leftSum;
    }
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;

    int ans = maxPath(root, res);
    if (root->left && root->right)
    {
        return res;
    }

    return max(ans, res);
}

//        3
//      /    \                          
//    4       5
//   /  \      
// -10   4

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << maxPathSum(root);
}