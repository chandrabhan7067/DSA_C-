#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter\n";
    cin>>n;
    int sum = 0;
    int product = 1;

    while (n != 0)
    {
        int digit = n%10;
        sum += digit;
        product *= digit;
        n /= 10;
    }
    int ans = product - sum;
    cout<<ans;

  
    
}