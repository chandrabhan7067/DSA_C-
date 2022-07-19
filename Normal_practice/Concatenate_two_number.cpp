#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
using namespace std;

int concatenateNumber(int x, int n,vector<int>numbers){
    unordered_map<string,int>m;

    for (int i = 0; i < n; i++)
    {
        m[to_string(numbers[i])]++;
    }
    
    string s = to_string(x);
    long long int ans = 0;
    for (int i = 1; i < s.size(); i++)
    {
        string first = s.substr(0,i);
        string second = s.substr(i);

        if(first == second){
            ans += m[first] *(m[second]-1);
        }
        else{
            ans += m[first]*m[second];
        }
    }
    return ans;

}

int main()
{
    vector<int>number{11, 11, 110};
    int n = number.size();
    int x = 11011;
    cout<<concatenateNumber(x,n,number);

}