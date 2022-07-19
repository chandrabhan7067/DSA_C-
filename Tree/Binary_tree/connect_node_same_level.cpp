#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *nextRight;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->nextRight = NULL;
    }
};

void connectNode(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *nextPoint = NULL;
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            frontNode->nextRight = nextPoint;
            nextPoint = frontNode;

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
            if (frontNode->left)
            {
                q.push(frontNode->right);
            }
        }
    }
}