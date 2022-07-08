#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string minimumSum(int arr[], int n){
    sort(arr, arr + n);

    string a = "", b = "";

    for (int i = 0; i < n; i += 2)
    {
        a += (arr[i] + '0');
    }

    for (int i = 1; i < n; i += 2)
    {
        b += (arr[i] + '0');
    }

    int j = a.length() - 1;
    int k = b.length() - 1;
    int carry = 0;
    string ans = "";
    int sum = 0;

    while(j >= 0 && k >= 0){
        sum = (a[j] - '0') + (b[k] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
        k--;
    }

    while(j >= 0){
        sum = (a[j] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
    }
    
    while(k >= 0){
        sum = (b[k] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        k--;
    }
    
    if(carry){
        ans += to_string(carry);
    }

    while(!ans.empty() && ans.back() == '0'){
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;

}

int main()
{
    int arr[] = {5, 3, 0, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    string ans = minimumSum(arr,n);
    cout<<ans;
}