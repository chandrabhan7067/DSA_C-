#include<iostream>
#include<vector>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

// leaf node in n/2+1....n
void buildHeap(int arr[], int n){
    for(int i = n/2; i > 0; i--){
        heapify(arr,n,i);
    }
}

void HeapSort(int arr[], int n){
    // buildHeap(arr,n);

    int size = n;

    while(size > 1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }    
}

int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    int n= 5;

    for(int i = n/2; i > 0; i--){
        heapify(arr,n,i);
    }

    HeapSort(arr,n);
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
}