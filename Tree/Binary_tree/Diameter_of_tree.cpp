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

int Diameter(Node *root){
    if(root == NULL){
        return 0;
    }

    int op1 = Diameter(root->left);
    int op2 = Diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(op1,max(op2,op3));

    return ans;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<Diameter(root);
}