#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0'; // this is for converting character to integer
    string temp = mapping[number];

    for (int i = 0; i < temp.length(); i++)
    {
        output.push_back(temp[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

int main()
{
    string digit = "23";
    vector<string> ans;
    string output = "";
    int index = 0;
    string array[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digit, output, index, ans, array);
    print(ans);
    //  ["ad","ae","af","bd","be","bf","cd","ce","cf"]
}