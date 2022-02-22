#include <iostream>
using namespace std;

// 4 = binary number = 100
// 1 0 0
//   & 1
//     0

int main()
{
    int n = 11;

    if (n & 1)
    {
        cout << "odd";
    }
    else
    {
        cout << "Even";
    }
}