#include <iostream>
#include<queue>
#include<vector>
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

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data :" << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

vector<int>zigzag_traversal(Node *root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }

    queue<Node*>q;
    q.push(root);
    bool leftToRIght = true;

    while(!q.empty()){
        int n = q.size();
        vector<int>tempAns(n);

        for(int i = 0; i < n; i++){
            Node *frontNode = q.front();
            q.pop();

            if(leftToRIght){
                tempAns[i] = frontNode->data;
            }
            else{
                tempAns[n-i-1] = frontNode->data;
            }


            if(frontNode->left){
                q.push(frontNode->left);
            }

            if(frontNode->right){
                q.push(frontNode->right);
            }
        }

        leftToRIght = !leftToRIght;

        for(auto i : tempAns){
            ans.push_back(i);
        }
    }
    return ans;
}


int main(){
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = zigzag_traversal(root);
    for(int i:ans){
        cout<<i<<" ";
    }
}