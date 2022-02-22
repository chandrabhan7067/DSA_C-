#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a input" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int k = 1; k <= i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}