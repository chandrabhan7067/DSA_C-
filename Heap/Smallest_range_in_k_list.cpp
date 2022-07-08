#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;


class Node{
    public:
        int data;
        int row;
        int col;

        Node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(Node *a, Node *b){
            return a->data > b->data;
        }
};

pair<int,int>findSmallestRange(int arr[][4], int n, int k){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>,compare > minHeap;

    for (int i = 0; i < k; i++)
    {
        int element = arr[i][0];
        int maxi = max(maxi,element);
        int mini = min(mini,element);
        minHeap.push(new Node(element,i,0));
    }
    
    int start = mini, end = maxi;

    while(!minHeap.empty()){
        Node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

// checking next element exist or not
        if(temp->col + 1 < n){
            maxi = max(maxi, arr[temp->row][temp->col + 1]);
            minHeap.push(new Node(arr[temp->row][temp->col + 1],temp->row, temp->col + 1));
        }

        else{
            break;
        }
    }

    return {start,end};
}


int main()
{
    int arr[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12}};

    int n = 4;
    int k = 3;
    pair<int,int>ans = findSmallestRange(arr,n,k);
    cout<<ans.first<<endl;
    cout<<ans.second;
}