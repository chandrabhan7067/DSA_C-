#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallerPro = factorial(n - 1);
    int biggerPro = n * smallerPro;
    // return n * factorial(n - 1);
    return biggerPro;
}

int main()
{
    int n;
    cout << "Enter\n";
    cin >> n;

    int ans = factorial(n);
    cout << ans;
}