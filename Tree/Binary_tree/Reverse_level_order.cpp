#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int value){
            this->data = value;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *buildTree(Node *root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left child of :"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right child of :"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void ReverseOrder(Node *root){
    stack<Node*>st;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        st.push(temp);

        if(temp->right){
            q.push(temp->right);
        }

        if(temp->left){
            q.push(temp->left);
        }
    }

    while(!st.empty()){
        Node *temp = st.top();
        cout<<temp->data<<" ";
        st.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    ReverseOrder(root);
}