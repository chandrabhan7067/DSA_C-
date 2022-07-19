#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

bool isMerror(int A[], int B[], int e)
{
    unordered_map<int, stack<int>> m;

    for (int i = 0; i < 2 * e; i += 2)
    {
        m[A[i]].push(A[i + 1]);
    }

    for (int i = 0; i < 2 * e; i += 2)
    {
        if (m[B[i]].top() != B[i + 1])
        {
            return false;
        }
        m[B[i]].pop();
    }
    return true;
}

int main()
{
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 2, 1, 3};
    int e = 2;
    cout<<isMerror(A,B,e);
}