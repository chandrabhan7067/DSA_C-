#include<iostream>
#include<vector>
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

Node *BuildTree(int parent[], int n){
    vector<Node*>child;

    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(i);
        child.push_back(temp);
    }
    
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        if(parent[i] == -1){
            root = child[i];
        }
        else{
            if(child[parent[i]]->left == NULL){
                child[parent[i]]->left = child[i];
            }
            else{
                child[parent[i]]->right = child[i];
            }
        }
    }
    return root;
}

void print(Node *root){
    if(root == NULL)
        return;
    
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    int parent[] = {-1,0,0,1,1,3,5};
    int n = sizeof(parent)/sizeof(parent[0]);
    Node *root = BuildTree(parent,n);
    print(root);
}