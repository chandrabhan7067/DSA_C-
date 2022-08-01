#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.


void topological(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> &visited, string &ans)
{

    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            topological(i, adj, visited, ans);
        }
    }

    char ch = node + 'a';
    ans += ch;
}

string findOrder(string dict[], int N, int K)
{

    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int n = min(s1.size(), s2.size());

        for (int j = 0; j < n; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    string ans = "";

    for (int i = 0; i < K; i++)
    {
        if (!visited[i])
            topological(i, adj, visited, ans);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string dict[] = {"caa", "aaa", "aab"};
    int N = 3, K = 3;

    cout << findOrder(dict, N, K);
}