#include<iostream>
#include<stack>
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

void rightToLeft(Node *root){
    if(root == NULL){
        return;
    }

    stack<Node*>st;
    st.push(root);

    while(!st.empty()){
        Node *forntNode = st.top();
        st.pop();
        cout<<forntNode->data<<" ";

        if(forntNode->left){
            st.push(forntNode->left);
        }
        if(forntNode->right){
            st.push(forntNode->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    rightToLeft(root);
}