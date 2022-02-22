#include<iostream>
using namespace std;

// void reverse(string& st,int s, int e){
//     if(s>=e){
//         return;
//     }
//     swap(st[s],st[e]);
//     return reverse(st,s+1,e-1);
// }


void reverse(string& st,int s){
    int n = st.size();
    int e = n - s -1;
    if(s>=e){
        return;
    }
    swap(st[s],st[e]);
    return reverse(st,s+1);
}

int main()
{
    string st = "abcde";
    int n = st.length();
    cout<<n<<endl;
    reverse(st,0);
    cout<<st;

}