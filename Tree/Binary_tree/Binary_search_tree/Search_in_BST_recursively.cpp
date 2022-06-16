#include <iostream>
using namespace std;

// time complexity  O(height of tree)   in case of skewed tree   O(n)
// space complexity   O(n)

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

Node *buildTree(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = buildTree(root->right, data);
    }

    else
        root->left = buildTree(root->left, data);

    return root;
}

Node *takeInput(Node *root)
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

bool Searching_recursively(Node *root, int value)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == value)
        return true;

    if (value > root->data)
        Searching_recursively(root->right, value);

    else
        Searching_recursively(root->left, value);
}

int main()
{
    Node *root = NULL;
    cout << "Enter the input for building the tree" << endl;
    root = takeInput(root);

    cout << Searching_recursively(root, 5);
}