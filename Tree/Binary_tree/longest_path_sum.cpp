#include <iostream>
#include <utility>
using namespace std;

// in pair we have first value if tree is true or false second is sum of tree

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

void solve(Node *root, int len, int &maxLen, int sum, int &maxSum)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxSum = sum;
            maxLen = len;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, len + 1, maxLen, sum, maxSum);
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

int longestPathSum(Node *root)
{
    int len = 0;
    int maxLen = -9999;
    int sum = 0;
    int maxSum = 0;
    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<longestPathSum(root);
}