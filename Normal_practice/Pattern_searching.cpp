#include<iostream>
using namespace std;

int searching(string s, string t){

    int i = 0, j = 0;

    while(i < s.size()){

        if(s[i] == t[j]){

            if(j == t.size()-1)
                return 1;

            i++;
            j++;
        }

        else{
            if(j == 0){
                i++;
            }
            else{
                j = 0;
            }
        }

    }
    return 0;
}

int main()
{
    string s = "geeksforgeeks";
    string t = "gfg";

    cout<<searching(s,t);
}