#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
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

vector<int> verticalTraversal(Node *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = verticalTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}