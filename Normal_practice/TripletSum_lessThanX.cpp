#include<iostream>
#include<algorithm>
using namespace std;

long long Count_tripletsWithSum_smaller_thanX(long long arr[], int sum, int n){
    long long cnt = 0;
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while(j < k){
            long long sumvalue = arr[i] + arr[j] + arr[k];

            if(sumvalue < sum){
                cnt += k - j;
                j++;
            }
            else{
                k--;
            }

        }
    }
return cnt;    

}

int main()
{
    long long arr[] = {-2, 0, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    cout<<Count_tripletsWithSum_smaller_thanX(arr,sum,n);
}