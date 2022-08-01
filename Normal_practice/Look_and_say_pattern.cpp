#include<iostream>
#include<string>
using namespace std;

string lookAndSay(int n){

    if(n == 1){
        return "1";
    }

    string s = "1";

    for (int i = 2; i <= n; i++)
    {
        s += '$';
        string temp = "";
        int cnt = 1;

        for(int j = 1; j < s.size(); j++){

            if(s[j] != s[j-1]){
                temp += to_string(cnt);
                temp += s[j-1];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        s = temp;
    }
    return s;
}

int main()
{
    int n = 3;
    cout<<lookAndSay(n);
}