#include <iostream>
#include <limits.h>
using namespace std;

bool Is_power_of_2(int n)
{
    int ans = 1;

    for (int i = 0; i <= 30; i++)
    {
        if (ans == n)
        {
            return true;
        }
        if (ans < INT_MAX / 2)
        {
            ans = ans * 2;
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter a input\n";
    cin >> n;

    if (Is_power_of_2(n))
    {
        cout << "yes the number is power of 2";
    }
    else
    {
        cout << "The number is not power of 2";
    }
}