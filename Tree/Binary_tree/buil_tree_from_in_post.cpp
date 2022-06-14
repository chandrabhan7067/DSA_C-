#include <iostream>
#include <vector>
#include<map>
using namespace std;

// time O(n logn)
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

void createMaping(int in[],int n, map<int,int>&mapping){
    for (int i = 0; i < n; i++)
    {
        mapping[in[i]] = i;
    }
    
}

Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n,map<int,int>&mapping){
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int element = post[index];
    index--;
    Node *root = new Node(element);
    int position = mapping[element];

    root->right = solve(in, post, index, position + 1, inorderEnd, n,mapping);
    root->left = solve(in, post, index, inorderStart, position - 1, n,mapping);

    return root;
}


Node *inorder_preorder(int in[], int post[], int n){
    int postorderIndex = n-1;
    map<int,int>mapping;
    createMaping(in, n, mapping);
    return solve(in, post, postorderIndex, 0, n-1, n,mapping); 
}

void print_tree(Node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    print_tree(root->left);
    print_tree(root->right);
}

int main()
{
    int in[] = {4,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};
    int n = 8;
    Node *root = inorder_preorder(in, post, n);
    print_tree(root);

}