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

Node *builBST(vector<int>inorderVal, int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s + e)/2;
    Node *root = new Node(inorderVal[mid]);
    root->left = builBST(inorderVal,s,mid-1);
    root->right = builBST(inorderVal,mid+1,e);
    return root;
}

int main()
{
    vector<int>sortedList{1,2,3,4,5};
    int s = 0;
    int e = sortedList.size()-1;
    cout<<builBST(sortedList,s,e)->right->data;    
}