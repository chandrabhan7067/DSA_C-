#include <iostream>
using namespace std;

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    int first = 0;
    int second = 1;
    int i = 0;

    while (i < n)
    {
        int sum = first + second;
        first = second;
        second = sum;
        i++;
    }
    cout<<first;
}

int main()
{
    int n;
    cout << "Enter" << endl;
    cin >> n;
    fib(n);
}