#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

// in this prooblem idea is that we are store a mapping for all the horizontal Nodes and only one mapping is available for one horizontal lavel

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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // in mapping first think is hd and second is Node->data data of particular Node
    map<int, int> mapping;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        if(mapping[hd] == 0)
        {
            mapping[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : mapping)
    {
        ans.push_back(i.second);
    }
    return ans;
}


int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = topView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}