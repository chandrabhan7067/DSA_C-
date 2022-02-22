#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b/2);

    if (ans %2 == 0)
    {
        // return a * ans * ans;
        return ans * ans;
    }
    else
    {
        // return ans * ans;
        return a * ans * ans;
    }
}

int main()
{
    int a;
    cout << "Enter" << endl;
    cin >> a;

    int b;
    cout << "Enter" << endl;
    cin >> b;

    int ans = power(a,b);
    cout<<"answer is: "<<ans;
}