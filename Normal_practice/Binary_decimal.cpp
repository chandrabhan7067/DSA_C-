#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter binary number\n";
    cin >> n;
    int i = 0;
    int sum = 0;

    while (n != 0)
    {
        if (n % 10 == 1)
        {
            sum = sum + pow(2, i);
        }
        n = n / 10;
        i++;
    }
    cout << sum;
}