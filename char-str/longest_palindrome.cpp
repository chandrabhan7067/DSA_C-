#include<iostream>
using namespace std;

void print(string s, int start, int end){
    for(int i = start; i < end; i++){
        cout<<s[i]<<" ";
    }
}

string LongestPalindrome(string s){
    int low,high;
    int start = 0;
    int len = 1;

    for(int i = 1; i < s.size(); i++){
        low = i - 1;
        high = i;

        while(low >= 0 && high < s.size() && s[low] == s[high]){
            if(high - low + 1 > len){
                start = low;
                len = high - low + 1;
            }
            low--;
            high++;
        }

        low = i - 1;
        high = i + 1;

        while(low >= 0 && high < s.size() && s[low] == s[high]){
            if(high - low + 1 > len){
                start = low;
                len = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start,len);
    // print(s,start,len);
}

int main()
{
    string st = "abc";
    string ans = LongestPalindrome(st);
    cout<<ans;
}