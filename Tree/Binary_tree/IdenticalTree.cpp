#include <iostream>
#include <utility>
using namespace std;

class Node{
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

bool idinticalTree(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if(r1 == NULL && r2 != NULL){
        return false;
    }

    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool left = idinticalTree(r1->left, r2->left);
    bool right = idinticalTree(r1->right,r2->right);
    bool condition = r1->data == r2->data;

    if(left && right && condition){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    Node *r1 = NULL;
    Node *r2 = NULL;
    r1 = buildTree(r1);
    cout<<"Enter the data for second tree"<<endl;
    r2 = buildTree(r2);
    cout<<idinticalTree(r1,r2);
}