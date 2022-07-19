#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};

void make_merror(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    swap(root->left, root->right);

    make_merror(root->left);

    make_merror(root->right);
}

int main()
{
    Node *root = NULL;
}