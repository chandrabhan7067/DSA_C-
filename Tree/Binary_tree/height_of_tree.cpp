#include <iostream>
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

int height(Node *root){
    if(root == NULL){
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    int ans = max(leftH,rightH) + 1;

    return ans;

}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<height(root);
}