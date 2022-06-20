#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>NextGreater(vector<int>arr,int n){
    stack<int>st;
    vector<int>ans(n);

    for(int i = n - 1; i >= 0; i--){
        int val = arr[i];

        while(!st.empty() && st.top() <= val){
            st.pop();
        }

        if(st.empty()){
            ans[i] = -1;
            st.push(val);
        }

        else{
            ans[i] = st.top();
            st.push(val);
        }
    }
    return ans;
}

void print(vector<int>ans){
    for(auto i:ans){
        cout<<i<<" ";
    }
}

int main()
{
    vector<int>arr{1, 3, 2, 4};
    int n = arr.size();
    vector<int>ans = NextGreater(arr,n);
    print(ans);
}