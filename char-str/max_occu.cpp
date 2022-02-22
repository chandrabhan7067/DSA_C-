#include <iostream>
using namespace std;

char maxi_occu(string st)
{
    int arr[26] = {0};

    for (int i = 0; i < st.length(); i++)
    {
        char ch = st[i];
        int number = 0;
        number = ch - 'a';
        // int number = st[i] - 'a';
        arr[number]++;
    }

    // find maximumn number
    int max = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            ans = i;        // ans store maximum number length
            max = arr[i];
        }
    }
    char final_ans = 'a' + ans;
    return final_ans;
}

int main()
{
    string s;
    cout << "Enter" << endl;
    cin >> s;
    cout << maxi_occu(s);

    // char ch = 'd';
    // int n = ch-'a';
    // cout<<n;

    // int i =25;
    // char ch = 'a' + i;
    // cout<<ch;
}