#include <iostream>
using namespace std;

int sqareRoot(int n)
{
    int multi = 1;
    int i = 1;
    int ans = 0;

    while (i <= n)
    {
        multi = i * i;

        if (multi <= n)
        {
            ans++;
            i++;
        }
        else if (multi > n)
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 899;
    cout << sqareRoot(n);
}