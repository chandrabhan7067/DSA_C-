#include <iostream>
#include <queue>
using namespace std;

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

Node *BuildBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = BuildBST(root->right, data);
    }

    else
    {
        root->left = BuildBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = BuildBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

Node *convertToList(Node *root)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    Node *head = new Node(inorderVal[0]);
    Node *curr = head;

    for (int i = 1; i < inorderVal.size(); i++)
    {
        Node *temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return head;
}

int main()
{
    Node *root = NULL;
    takeInput(root);
    cout<<convertToList(root)->data;
}