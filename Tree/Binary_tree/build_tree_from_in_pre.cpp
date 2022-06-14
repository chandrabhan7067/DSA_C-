#include <iostream>
#include <vector>
using namespace std;

// time O(n^2)
// space O(n)

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

int findPos(int in[], int n, int element){
    for (int i = 0; i < n; i++)
    {
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    int element = pre[index];
    index++;
    Node *root = new Node(element);
    int position = findPos(in, n, element);

    root->left = solve(in, pre, index, inorderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}


Node *inorder_preorder(int in[], int pre[], int n){
    int preorderIndex = 0;
    return solve(in, pre, preorderIndex, 0, n-1, n); 
}

void print_tree(Node *root){
    if(root == NULL){
        return;
    }

    print_tree(root->left);
    print_tree(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    int n = 6;
    Node *root = inorder_preorder(in, pre, n);
    print_tree(root);

}