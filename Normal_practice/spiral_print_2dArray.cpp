#include<iostream>
#include<vector>
using namespace std;

vector<int>solve(vector<vector<int>>arr){
    vector<int>ans;
    int row = arr.size();
    int col = arr[0].size();
    int totalEle = row*col;
    int count = 0;

    int startRow = 0;
    int endRow = row-1;
    int startCol = 0;
    int endCol = col-1;

    while(count < totalEle){
        for(int i = startCol; i <= endCol && count < totalEle; i++){
            ans.push_back(arr[startRow][i]);
            count++;
        }
        startRow++;

        for(int i = startRow; i <= endRow && count < totalEle; i++){
            ans.push_back(arr[i][endCol]);
            count++;
        }
        endCol--;

        for(int i = endCol; i >= startCol && count < totalEle; i--){
            ans.push_back(arr[endRow][i]);
            count++;
        }
        endRow--;

        for(int i = endRow; i>= startRow && count < totalEle; i--){
            ans.push_back(arr[i][startCol]);
            count++;
        }
        startCol++;
    }
    return ans;
}

int main()
{
    vector<vector<int>>array{{1,2,3},
                                {4,5,6},
                                {7,8,9}};

    vector<int>ans = solve(array);
    for(auto i:ans){
        cout<<i<<" ";
    }
}