#include <iostream>
using namespace std;

void say_degit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int degit = n % 10;
    n = n / 10;

    say_degit(n, arr);
    cout << arr[degit] << " ";
}

int main()
{
    int n;
    cout << "Enter" << endl;
    cin >> n;

    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    say_degit(n, arr);
}