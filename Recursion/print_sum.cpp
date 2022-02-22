#include <iostream>
using namespace std;

int count(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int small = count(n - 1);
    int big = n + small;
    return big;
    //   return n + count(n-1);
}

int main()
{
    int n;
    cout << "Enter" << endl;
    cin >> n;
    cout << count(n);
}