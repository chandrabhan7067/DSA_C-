#include<iostream>
using namespace std;

bool replace(char ch){
    if(ch>= 'A' && ch<= 'Z' || ch >= 'a' && ch<= 'z' || ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int main()
{
    string st = "A man, a plan, a canal: Panama";
    int i = 0;
    st.erase(st.begin() + i);
    st.erase(st.begin() + i + 1);
    cout<<st;

    // cout<<st<<endl;
    // int temp = 0;
    // string temp1 = "";
    // for(int i =0; i<st.size(); i++){
    //     if(replace(st[i])){
    //         st[temp] = st[i];
    //         temp1.push_back(st[i]);
    //         temp++;
    //     }
    // }
    // st.erase(st.size()+1,st.end());
    // cout<<st<<endl;
    // cout<<temp1;
}