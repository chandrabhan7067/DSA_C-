#include <iostream>
#include <vector>
#include <queue>
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

vector<int> DiagonalOrder(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    Node *currNode = root;

    while (currNode != NULL)
    {
        ans.push_back(currNode->data);

        if (currNode->left)
        {
            q.push(currNode->left);
        }

        if (currNode->right)
        {
            currNode = currNode->right;
        }

        else
        {
            if (!q.empty())
            {
                currNode = q.front();
                q.pop();
            }
            else
            {
                currNode = NULL;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = DiagonalOrder(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}