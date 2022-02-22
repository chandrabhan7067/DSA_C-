#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {5,2,3,4};
    cout<<"Address of array is:"<<arr<<endl;
    cout<<"Address of array is:"<<&arr[0]<<endl;

    cout<<"value at first: "<<*arr<<endl;
    cout<<"After value increment at first index: "<<*arr+1<<endl;
    cout<<"value at second: "<<*(arr+1)<<endl;

// Internal work 
// arr[2] = *(arr+2)
// 2[arr] = *(2+arr)

    cout<<arr[2]<<endl;
    cout<<*(arr+2)<<endl;

    cout<<2[arr]<<endl;
    cout<<*(arr+2)<<endl;

    int *ptr = &arr[0];
    cout<<"size of array is "<<sizeof(arr)<<endl;
    cout<<"size of array is "<<sizeof(ptr)<<endl;
    cout<<"size of array is "<<sizeof(*ptr)<<endl;
}