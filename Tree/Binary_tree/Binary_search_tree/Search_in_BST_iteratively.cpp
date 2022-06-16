#include <iostream>
using namespace std;


// time complexity  O(Height of tree)   in case of skewed tree   O(n)
// space complexity   O(1)

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

bool Searching_iteratively(Node *root, int value)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return true;
        }

        if (value > curr->data)
        {
            curr = curr->right;
        }

        else
        {
            curr = curr->left;
        }
    }
    return false;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the input for building the tree" << endl;

    root = takeInput(root);

    cout << Searching_iteratively(root, 5);
}