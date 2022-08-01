#include<iostream>
using namespace std;

string encode(string s)
{
    s += '$';
    int cnt = 1;
    string temp = "";

    for(int i = 1; i < s.size(); i++){

        if(s[i] == s[i-1]){
            cnt++;
        }
        else{
            temp += s[i-1];
            temp += to_string(cnt);
            cnt = 1;
        }

    }
    s = temp;
    return s;
}

int main()
{
    string s = "aaaabbbccc";
    cout<<encode(s);
}