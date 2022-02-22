#include<iostream>
using namespace std;

// bool Is_pali(string st,int s, int e){
//     if(s>=e){
//         return true;
//     }
//     if(st[s] != st[e]){
//         return false;
//     }
//     return Is_pali(st,s+1,e-1);
// }

// using one pointer
bool Is_pali(string st,int s){
    int n = st.size();
    int e = n - s - 1;
    if(s>=e){
        return true;
    }
    if(st[s] != st[e]){
        return false;
    }
    return Is_pali(st,s+1);
}

int main()
{
    string st = "abba";
    if(Is_pali(st,0)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}