#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

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

    cout << "Enter the data for left child of: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right child of: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Time  O(n)   but in worst case  O(n^2)
// space   O(n)

void spiralPrint(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {

        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            if (temp->right)
            {
                s2.push(temp->right);
            }

            if (temp->left)
            {
                s2.push(temp->left);
            }
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            if (temp->left)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    spiralPrint(root);
}