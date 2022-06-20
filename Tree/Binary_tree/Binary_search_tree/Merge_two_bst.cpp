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


void mergeArray(vector<int>arr1,vector<int>arr2,int n, int m,vector<int>&newArray){
    
    int i = 0, j = 0, k = 0;

    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            newArray[k] = arr1[i];
            i++;
            k++;
        }

        else{
            newArray[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < n){
        newArray[k] = arr1[i];
        i++;
        k++;
    }

    while(j < m){
        newArray[k] = arr2[j];
        j++;
        k++;
    }
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    cout<<"Enter data"<<endl;
    takeInput(root1);
    cout<<"Enter data for second tree"<<endl;
    takeInput(root2);

    vector<int>inorder1;
    vector<int>inorder2;
       
    inorder(root1,inorder1);
    inorder(root2,inorder2);

    int n = inorder1.size();
    int m = inorder2.size();

    vector<int>ans(n + m);
    mergeArray(inorder1,inorder2,n,m,ans);

    for(auto i:ans){
        cout<<i<<" ";
    }
}