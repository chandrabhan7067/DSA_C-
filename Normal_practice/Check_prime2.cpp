#include <iostream>
#include <vector>
using namespace std;

// time complexity is   o(n^2)

// bool Isprime(int n)
// {
//     if (n <= 1)
//     {
//         return false;
//     }
//     for (int i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     int n;
//     cout << "Enter" << endl;
//     cin >> n;

//     int count = 0;
//     for (int i = 2; i < n; i++)
//     {
//         if (Isprime(i))
//         {
//             count++;
//         }
//     }
//     cout << count;
// }


// time complexity is
//  n/2 + n/3 + n/5 + n/7......

//  O(n*log(log n))

int main()
{
    int n;
    cout << "Enter" << endl;
    cin >> n;
    int cnt = 0;
    vector<bool> prime(n, true);

    // prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;

            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    cout << cnt;
}