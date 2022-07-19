#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

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

void helper1(Node *root, vector<int>&serializevec){
    if(!root){
        serializevec.push_back(-1);
        return;
    }

    serializevec.push_back(root->data);
    helper1(root->left,serializevec);
    helper1(root->right,serializevec);
}

Node*helper2(vector<int>&v, int& i){
    if(v[i] == -1){
        return NULL;
    }

    Node *root = new Node(v[i]);
    root->left = helper2(v,++i);
    root->right = helper2(v,++i);

    return root;
}

vector<int>serialize(Node *root){
    vector<int>ans;
    helper1(root,ans);
    return ans;
}

Node *deserialize(vector<int>seria){
    int i = 0;
    return helper2(seria,i);
}

void print(Node *root){
    if(!root)
        return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>seri = serialize(root);
    root = deserialize(seri);
    print(root);
}
