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

void left_traversal(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        left_traversal(root->left, ans);
    }
    else
    {
        left_traversal(root->right, ans);
    }
}

void leafNode_traversal(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leafNode_traversal(root->left, ans);
    leafNode_traversal(root->right, ans);
}

void right_traversal(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        right_traversal(root->right, ans);
    }
    else
    {
        right_traversal(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> Boundary_traversal(Node *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // for printing all left Node
    left_traversal(root->left, ans);

    // for printing all leaf node  of left subtree
    leafNode_traversal(root->left, ans);

    // for printing all leaf node  of right subtree
    leafNode_traversal(root->right, ans);

    //  for printing all right nodes
    right_traversal(root->right, ans);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    vector<int> ans = Boundary_traversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
