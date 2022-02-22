#include <iostream>
using namespace std;

int countbits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main()
{
    int a, b;
    cout << "Enter\n";
    cin >> a;
    cout << "Enter\n";
    cin >> b;
    cout << countbits(a ^ b);       // XOR
}