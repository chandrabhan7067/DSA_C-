#include <iostream>
#include <queue>
using namespace std;

// time copmlexity   O(H)
 
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

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << frontNode->data << " ";

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node *DeleteNode(Node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->data == value)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        //  right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = DeleteNode(root->right, mini);
            return root;
        }
    }

    if (root->data > value)
    {
        root->left = DeleteNode(root->left, value);
        return root;
    }

    else
    {
        root->right = DeleteNode(root->right, value);
        return root;
    }
}

Node *builTree(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = builTree(root->right, data);
    }

    else
    {
        root->left = builTree(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = builTree(root, data);
        cin >> data;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for building the tree" << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelOrder(root);

    cout << "Inorder traversal" << endl;
    inorder(root);

    cout << endl<< "preorder traversal" << endl;
    preorder(root);

    cout << endl<< "postorder traversal" << endl;
    postorder(root);

    root = DeleteNode(root,50);

    cout<<"After delete the node"<<endl;
    cout << "printing the tree" << endl;
    levelOrder(root);

    cout << "Inorder traversal" << endl;
    inorder(root);

    cout << endl<< "preorder traversal" << endl;
    preorder(root);

    cout << endl<< "postorder traversal" << endl;
    postorder(root);    
}