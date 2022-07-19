#include<iostream>
#include<algorithm>
#include<stack>
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

vector<int>postorder(Node *root){
    vector<int>ans;
    stack<Node*>s;
    Node *curr = root;

    while(curr || !s.empty()){
        ans.push_back(curr->data);

        if(curr->left){
            s.push(curr->left);
        }

        if(curr->right){
            s.push(curr->right);
        }

        if(!s.empty()){
            curr = s.top();
            s.pop();
        }
        else{
            curr = NULL;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = postorder(root);

    for(auto i:ans){
        cout<<i<<" ";
    }
}