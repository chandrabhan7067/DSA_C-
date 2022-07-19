#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

// time complexity   O(n^2)
// space complexity  O(1)

vector<int> Factorial(int n)
{
    vector<int> ans;
    ans.push_back(1);

    for (int x = 2; x <= n; x++)
    {
        int carry = 0;

        for (int i = 0; i < ans.size(); i++)
        {
            int val = x * ans[i] + carry;
            ans[i] = val % 10;
            carry = val / 10;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 76;
    vector<int>ans = Factorial(n);

    for(auto i:ans){
        cout<<i<<" ";
    }
}