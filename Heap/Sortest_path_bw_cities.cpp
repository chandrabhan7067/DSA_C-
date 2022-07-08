#include<iostream>
#include<queue>
using namespace std;

int SortestPath(int x, int y){
    int ans = 0;

    while(x != y){
        if(x > y){
            x /= 2;
            ans++;
        }
        else{
            y /= 2;
            ans++;
        }
    }
    return ans;
}

int main()
{
    int x = 2, y = 6;
    cout<<SortestPath(x,y);
}