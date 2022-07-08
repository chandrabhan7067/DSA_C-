#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void solve(set<string> &sets, int n, string S, int index)
{
    if (n <= index)
    {
        sets.insert(S);
        return;
    }

    for (int i = index; i < n; i++)
    {
        swap(S[index], S[i]);
        solve(sets, n, S, index + 1);
        swap(S[index], S[i]);
    }
}

vector<string> permutation(string s, int n)
{
    set<string> sets;
    vector<string> ans;
    int index = 0;
    solve(sets, n, s, index);

    for (auto i : sets)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    string st = "ABC";
    int n = st.size();
    vector<string>ans = permutation(st,n);

    for(auto i :ans){
        cout<<i<<" ";
    }
}

// ABC ACB BAC BCA CAB CBA