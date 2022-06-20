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

void CountNodeLieInRange(Node *root,int l, int h, int &cnt){
    if(root == NULL){
        return;
    }

    if(root->data >= l && root->data < h){
        cnt++;
    }

    if(root->left){
        CountNodeLieInRange(root->left, l, h, cnt);
    }

    if(root->right){
        CountNodeLieInRange(root->right, l, h, cnt);
    }
}

//      5
//     /  \
//    4    6
//   /      \
//  3        7

// l = 2, h = 8


int main()
{
    Node *root = NULL;
    takeInput(root);
    int cnt = 0;
    int l = 2, h = 8;
    CountNodeLieInRange(root,l,h,cnt);
    cout<<cnt;
}