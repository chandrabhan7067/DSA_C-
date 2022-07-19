#include<iostream>
#include<unordered_map>
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

unordered_map<string,int>m;

string solve(Node *root){
    if(root == NULL){
        return "$";
    }

    string s = "";

    if(root->left == NULL && root->right == NULL){
        string s = to_string(root->data);
        return s;
    }

    s = s + to_string(root->data);
    s = s + solve(root->left);
    s = s + solve(root->right);
    m[s]++;
    return s;
}

int findDuplicate(Node *root){
    solve(root);
    for(auto i:m){
        if(i.second >= 2)
            return 1;
    }
    return 0;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<findDuplicate(root);
}