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
// O(log n)

    void insert(int data){
        size = size + 1;
        int index = size;
        arr[index] = data;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }


// O(log n)
    void deleteFromHeap(){
        if(size == 0){
            cout<<"No element in heap"<<endl;
            return;
        }

        // step 1 put last element at first index
        arr[1] = arr[size];

        //step2 remove last element
        size--;

        // step3 mantain max heap

        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && arr[leftIndex] > arr[i]){
                swap(arr[leftIndex], arr[i]);
            }

            else if(rightIndex < size && arr[rightIndex] > arr[i]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();
}