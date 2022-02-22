#include <iostream>
using namespace std;

void update(int &n){
    n++;
}

int main()
{
    // int arr[] = {2,3,4};
    // cout<<arr<<endl;
    // cout<<*arr<<endl;
    // cout<<&arr[0];

    // char arr1[] = "chan";
    // cout<<arr1<<endl;
    // cout<<*arr1<<endl;
    // cout<<&arr1[0];

    char arr1 = 'c';
    char *p = &arr1;
    cout<<p<<endl;

    int n =3;
    cout<<n;
    update(n);
    cout<<n;

}