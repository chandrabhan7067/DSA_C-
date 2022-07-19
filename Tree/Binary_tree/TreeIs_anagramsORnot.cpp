#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left = NULL;
        Node *right = NULL;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node * buildTree(Node *root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left child of: "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right child of: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

bool isAnagrams(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1 == NULL && root2 != NULL)
        return false;

    if(root1 != NULL && root2 == NULL)
        return false;

    bool left = isAnagrams(root1->left, root2->right);
    bool right = isAnagrams(root1->right, root2->left);
    bool condition = root2->data == root2->data;

    if(left && right && condition)
        return true;
    return false;
}

int main()
{
    Node *root1 = NULL;
    root1 = buildTree(root1);
    cout<<"Enter data for next tree"<<endl;
    Node *root2 = NULL;
    root2 = buildTree(root2);

    cout<<isAnagrams(root1, root2);
}