#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

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

void treeToLinkedList(Node *root)
{
    Node *curr = root;

    while (curr != NULL)
    {

        if (curr->left)
        {
            Node *pre = root->left;

            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    treeToLinkedList(root);
}