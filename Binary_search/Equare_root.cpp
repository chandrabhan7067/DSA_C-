#include <iostream>
using namespace std;

long long int Root(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = 0;

    while (s <= e)
    {
        long long int equare = mid * mid;
        if (equare == n)
        {
            return mid;
        }
        else if (equare < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double Moreclear(int n, int precision, int temp)
{
    double factor = 1;
    double ans = temp;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter\n";
    cin >> n;
    int temp = Root(n);
    cout << Moreclear(n, 3, temp);
}