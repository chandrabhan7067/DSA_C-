#include <iostream>
using namespace std;

// time complexity  O(Height of tree)   in case of skewed tree   O(n)
// space complexity   O(H)

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

Node *findMin(Node *root)
{
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node *findMax(Node *root)
{
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

void PredecessorAnsSuccessor(Node *root, Node *&pre, Node *&Succ, int value)
{
    if (root == NULL)
        return;

    if (value == root->data)
    {
        if (root->left != NULL)
        {
            pre = findMax(root->left);
        }

        if (root->right)
        {
            Succ = findMin(root->right);
        }
    }

    if (value > root->data)
    {
        PredecessorAnsSuccessor(root->right, pre, Succ, value);
    }

    else
    {
        PredecessorAnsSuccessor(root->left, pre, Succ, value);
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter the input for building the tree" << endl;

    root = takeInput(root);
    Node *pre = NULL;
    Node *succ = NULL;
    PredecessorAnsSuccessor(root, pre, succ, 15);

    if (pre != NULL)
    {
        cout << pre->data << " ";
    }
    else
    {
        cout << "Predecessor is not present" << endl;
    }

    if (succ != NULL)
    {
        cout << succ->data << " ";
    }
    else
    {
        cout << "Successor is not present" << endl;
    }
}