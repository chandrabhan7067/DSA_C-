#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// space O(k)

class Node{
    public:
        int data;
        int i;
        int j;

        Node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
};

class compare{
    public:
        bool operator()(Node *a, Node *b){
            return a->data > b->data;
        }
};

vector<int>mergerKsortedArray(vector<vector<int>>arr, int k){
    priority_queue<Node*, vector<Node*>, compare >minHeap;

    // step 1 array ke first element ko insert krna h minHeap me

    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(arr[i][0],i,0);
        minHeap.push(temp);
    }
    
    vector<int>ans;

    while(minHeap.size() > 0){
        Node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j + 1 < arr[i].size()){
            Node *next = new Node(arr[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()
{
    Node *temp1 = new Node(10,0,0);
    Node *temp2 = new Node(20,0,0);
    compare ob;
    ob.operator()(temp1,temp2);
}