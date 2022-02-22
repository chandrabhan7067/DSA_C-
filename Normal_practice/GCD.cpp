#include <iostream>
using namespace std;

// formula
// gcd(a,b) = gcd(a-b,b)

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    int a, b;
    cout << "Enter" << endl;
    cin >> a;
    cin >> b;

    cout << gcd(a, b);
}