#include <iostream>
using namespace std;

// Benafite of using to inline function is we dont need to extra space 
// redability

inline int GetMax(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 1, b = 2;
    int ans = 0;

    ans = GetMax(a, b);
    cout << ans << endl;

    a = a + 5;
    b = b + 1;

    ans = GetMax(a, b);
    cout << ans;
}