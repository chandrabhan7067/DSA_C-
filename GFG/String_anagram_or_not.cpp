#include<iostream>
using namespace std;

// A string is an Anagram if the character of string a and character of string b is same only the order of character can be different

bool Anagram(string a, string b){
    if(a.size() != b.size()){
        return false;
    }

    int s1 = 0, s2 = 0;

    for(int i = 0; i < a.size(); i++){
        s1 += a[i];
        s2 += b[i];
    }

    if(s1 == s2){
        return true;
    }
    else   
        return false;
}

int main()
{
    string a = "abacd";
    string b = "daacb";
    cout<<Anagram(a,b);
}