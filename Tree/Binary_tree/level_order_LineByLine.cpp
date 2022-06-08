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

vector<vector<int>>levelOrder(Node *root)
{
    vector<vector<int>>ans;
    if(root == NULL){
        return ans;
    }

    queue<Node*>q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int>inner;

        while(n--){
            Node *temp = q.front();
            inner.push_back(temp->data);
            q.pop();
    
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(inner);
    }
    return ans;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout << "level order travalsal" << endl;
    vector<vector<int>>ans = levelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<" $ ";
    }
    
}