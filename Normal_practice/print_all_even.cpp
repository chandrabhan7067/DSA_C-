#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a input" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << "All even number is:" << endl;
            cout << i << endl;
        }
        else
        {
            cout << "All odd number is:" << endl;
            cout << i << endl;
        }
    }
}
