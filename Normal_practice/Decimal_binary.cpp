#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter\n";
    cin >> n;
    int remainder;
    int ans = 0;
    int i = 0;

    while (n != 0)
    {
        remainder = n%2;
        ans = (remainder * (pow(10, i))) + ans;
        n = n / 2;
        i++;
    }
    cout << ans;
    // cout<<45%10;
}


// int main()
// {
//     int n;
//     cout<<"Enter\n";
//     cin>>n;
//     int remainder;
//     int ans = 0;

//     while (n != 0)
//     {
//         remainder = n%2;
//         ans = ans*10+remainder;
//         n = n/2;
//     }
//     cout<<ans;
// }


// int main()
// {
//     int n;
//     cout<<"Enter";
//     cin>>n;
//     int i = 0;
//     int ans = 0;

//     while (n != 0)
//     {
//         int bit = n&1;
//         ans = (bit*pow(10,i))+ans;

//         n = n>>1;
//         i++;
//     }
//     cout<<ans;

// }