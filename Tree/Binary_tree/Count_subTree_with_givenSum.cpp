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


// time   O(N)
// space  O(height of tree)

int subtreeWithSum(Node *root, int s, int &ans){
    if(!root)
        return 0;

    int left = subtreeWithSum(root->left,s,ans);
    int right = subtreeWithSum(root->right,s,ans);

    int sum = left + right + root->data;

    if(sum == s)
        ans++;
    return sum;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int ans = 0;
    int s = 5;
    subtreeWithSum(root,s,ans);
    cout<<ans;
}