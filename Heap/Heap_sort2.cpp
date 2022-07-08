#include<iostream>
#include<vector>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i+2;

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

void buildHeap(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr,n,i);
    }
}

// leaf node in n/2...n

void HeapSort(int arr[], int n){
    // build tree

    for(int i = n/2-1; i >= 0; i--){
        heapify(arr,n,i);
    }

    int size = n-1;

    while(size > 0){
        swap(arr[size],arr[0]);
        heapify(arr,size,0);
        size--;
    }    
}

int main()
{
    int arr[] = {5,7,21,6,1};
    int n= 5;

    HeapSort(arr,n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}