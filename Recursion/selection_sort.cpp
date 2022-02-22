// #include <iostream>
// using namespace std;

// void print(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void Insertion_sort(int arr[], int n)
// {
//     // print(arr, 5);
//     if (n == 0 || n == 1)
//     {
//         return;
//     }
//     int key = arr[i];
//     int j = i - 1;
//     while (arr[j] > key && j >= 0)
//     {
//         arr[j + 1] = arr[j];
//         j--;
//     }
//     arr[j + 1] = key;
//     i = i + 1;
//     Insertion_sort(arr+1, n - 1);
// }

// int main()
// {
//     int arr[10] = {3, 0, 7, 2, 8};
//     int n = 5;
//     Insertion_sort(arr, 5, 1);
//     // print(arr, n);
// }