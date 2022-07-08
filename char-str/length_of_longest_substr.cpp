#include<iostream>
#include<limits.h>
using namespace std;

int longest_substring(string s){
    int n = s.length();
    int i = 0;
    int j = 0;
    int arr[26] = {0};
    int ans = INT_MIN;

    while(j < n){
        arr[s[j] - 'a']++;

        while(i < n && arr[s[j] - 'a'] != 1){
            arr[s[i] - 'a']--;
            i++;
        }

        ans = max(j - i + 1, ans);
        j++;
    }
    return ans;
}

int main()
{
    string s  = "abdefgabef";
    cout<<longest_substring(s);
}