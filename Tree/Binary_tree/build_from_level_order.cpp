#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

void BuildFromLevelOrder(Node *&root){
    queue<Node*>q;
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();


        cout<<"Enter the left child for :"<<temp->data<<endl;
        int leftNode;
        cin>>leftNode;

        if(leftNode != -1){
            temp->left = new Node(leftNode);
            q.push(temp->left);
        }


        cout<<"Enter the right child for :"<<temp->data<<endl;
        int rightNode;
        cin>>rightNode;

        if(rightNode != -1){
            temp->right = new Node(rightNode);
            q.push(temp->right);
        }

    }
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    BuildFromLevelOrder(root);
    levelOrder(root);

}