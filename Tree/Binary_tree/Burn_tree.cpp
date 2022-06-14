#include <iostream>
#include <map>
#include <queue>
using namespace std;

// four simple steps of algo
// create mapping node to parent
// search the target Node in tree;
// burn the tree in min time
// if any element is pushed in queue then only we will increase the ans/burnTime

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

// first two steps are done using this function

Node *Node_to_parentMapping(Node *root, int target, map<Node *, Node *> &NodeToParent)
{
    queue<Node *> q;
    q.push(root);
    NodeToParent[root] = NULL;
    Node *result = NULL;

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode->data == target)
        {
            result = frontNode;
        }

        if (frontNode->left)
        {
            NodeToParent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }

        if (frontNode->right)
        {
            NodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return result;
}

// third step is done by using this function

void burnTree(Node *root, int &ans, map<Node *, Node *> &NodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int size = q.size();

        // for checking any element is pushed in queue are not
        bool flag = false;

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            if (frontNode->left && !visited[frontNode->left])
            {
                visited[frontNode->left] = true;
                q.push(frontNode->left);
                flag = true;
            }

            if (frontNode->right && !visited[frontNode->right])
            {
                visited[frontNode->right] = true;
                q.push(frontNode->right);
                flag = true;
            }

            if (NodeToParent[frontNode] && !visited[NodeToParent[frontNode]])
            {
                visited[NodeToParent[frontNode]] = true;
                q.push(NodeToParent[frontNode]);
                flag = true;
            }
        }

// fourth step
        if (flag == true)
        {
            ans++;
        }
    }
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> NodeToParentMap;
    Node *targetNode = Node_to_parentMapping(root, target, NodeToParentMap);
    int ans = 0;
    burnTree(targetNode, ans, NodeToParentMap);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int target = 8;
    cout << minTime(root, target);
}