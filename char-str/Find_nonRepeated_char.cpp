#include<iostream>
#include<map>
using namespace std;

char findNonRepeated(string S){
    map<char,int>mapping;
    
    for(int i = 0; i < S.size(); i++){
        mapping[S[i]]++;
    }
    
    for(int i = 0; i < S.size(); i++){
        if(mapping[S[i]] <= 1){
            return S[i];
        }
    }
    return '$';    
}

int main()
{
    string S = "loveleetcode";
    char ch = findNonRepeated(S);
    cout<<ch;
}