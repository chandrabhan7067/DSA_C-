#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a input\n";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout<<n-j<<" ";
        }
        cout<<endl;
    }

    // int a = 'a';
    // char ch = 97;
    // cout<<ch;
    // cout<<a;
    
}