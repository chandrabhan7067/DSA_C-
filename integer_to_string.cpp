#include<iostream>
using namespace std;

int main()
{
// convert number to string or character
    int arr[] = {49,50,51};
    string ans = "";

    for (int i = 0; i < 3; i++)
    {
        ans = (arr[i] + '0');
        cout<<ans<<" ";
    }

// convert string to its corosponding value
    string st = "abc";
    int a;
    cout<<endl;

    for (int i = 0; i < 3; i++)
    {
        a = st[i] - '0';
        cout<<a<<" ";
    }

// convert string to number
    cout<<endl;
    string st2 = "abc";
    int b;

    for (int i = 0; i < 3; i++)
    {
        b = st2[i] - 'a';
        cout<<b<<" ";
    }
}