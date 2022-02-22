#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int>OnePlus(vector<int>v,int n){
    int e = n-1;
    
    while(e>=0){
        if(v[e] != 9){
            v[e]++;
            return v;
        }
        else{
            v[e] = 0;
            e--;
        }
    }
    v.insert(v.begin(),1);
    return v;
}

int main()
{
    vector<int> arr{9, 9, 9};
    int n = arr.size();
    print(OnePlus(arr,n++), n);
}