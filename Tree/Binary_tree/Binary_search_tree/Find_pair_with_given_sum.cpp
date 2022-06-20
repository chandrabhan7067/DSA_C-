#include <iostream>
#include <queue>
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

Node *BuildBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = BuildBST(root->right, data);
    }

    else
    {
        root->left = BuildBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = BuildBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool pairWithGivenSum(Node *root, int target)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0, j = ans.size() - 1;
    int sum = 0;

    while (i < j)
    {
        sum = ans[i] + ans[j];

        if (target == sum)
        {
            return true;
        }

        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data for building the BST " << endl;
    takeInput(root);
    cout<<pairWithGivenSum(root,2);
}