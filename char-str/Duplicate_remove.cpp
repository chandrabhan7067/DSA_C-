#include<iostream>
#include<math.h>
using namespace std;

string remove_duplicate(string st){
    int i = 0;

    if(st.length() >= pow(10,5)){
        return "";
    }

    while (i < st.size() - 1 && st.length() >= 2)
    {
        if(st[i] == st[i+1]){
            st.erase(st.begin()+i);
            st.erase(st.begin()+i);
            i = 0;
        }
        else{
            i++;
        }
    }
    return st;
}

int main()
{
    string st = "aaaaaa";
    cout<<st<<endl;
    cout<<remove_duplicate(st);
}