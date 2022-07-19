#include<stack>
#include<iostream>
#include<vector>
using namespace std;

bool isPermutation(vector<int>a,vector<int>b,int n){
    int j = 0;
    stack<int>s;

    for (int i = 0; i < n; i++)
    {
        s.push(a[i]);

        while(!s.empty() && s.top() == b[j]){
            s.pop();
            j++;
        }
    }
    
    // if(s.empty()){
    //     return true;
    // }
    // return false;
    return s.empty();
}

int main()
{
    vector<int>a{1,2,3};
    vector<int>b{2,1,3};
    int n = a.size();
    cout<<isPermutation(a,b,n);
}