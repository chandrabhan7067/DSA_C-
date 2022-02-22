#include<iostream>
using namespace std;

int power(int n){
    if (n == 0)
    {
        return 1;
    }

    // int smallerPro = power(n-1);
    // int biggerPro = 5 * smallerPro;
    return 2*power(n-1);
    // return biggerPro;
}

int main()
{
    int n;
    cout<<"Enter\n";
    cin>>n;

    int ans = power(n);
    cout<<ans;
}