#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter row";
    cin >> row;

    int column;
    cout << "Enter column";
    cin >> column;

    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }

    // Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    }

    // output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}