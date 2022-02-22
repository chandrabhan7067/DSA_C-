#include <iostream>
using namespace std;

void counting(int n)
{
    if (n == 0)
    {
        return;
    }

    // head recursion relation
    counting(n - 1);

    cout << n << " ";

    // tail recursion relation
    // counting(n - 1);
}

int main()
{
    int n;
    cout << "Enter" << endl;
    cin >> n;
    counting(n);
}