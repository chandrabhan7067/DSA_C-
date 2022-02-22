#include <iostream>
using namespace std;

void Isprime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "Number is prime:";
            return;
        }
    }
    cout << "Number is not prime";
}

int main()
{
    int n;
    cout << "Enter a input:" << endl;
    cin >> n;
    Isprime(n);
}