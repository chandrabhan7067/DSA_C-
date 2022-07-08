#include<iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            arr[0] = -1;
            this->size = 0;
        }
};

// O(log n)

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

// time complexity of building a heap O(n)

int main()
{

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

// O(n)
    for(int i = n/2; i > 0; i--){
        heapify(arr,5,i);
    }

    cout<<"printing..."<<endl;

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
}