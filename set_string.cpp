#include<iostream>
#include<string>
#include<set>
using namespace std;

// set has a propertiey that story only unique element and story element in asceding order

int main()
{
    set<int>st;

    // st.insert("acb");
    // st.insert("abc");

    st.insert(2);
    st.insert(1);
    st.insert(0);
    st.insert(1);

    for(auto i:st){
        cout<<i<<" ";
    }




}