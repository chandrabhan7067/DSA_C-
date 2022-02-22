#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// time complexity is O(nlogn)

// void Arange_array(int arr[], int n)
// {
//     int *A = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         A[i] = arr[i];
//     }
//     sort(A, n);
//     print(A, n);
//     int mid = n / 2;
//     int even = 1;
//     int odd = 0;

//     if (mid % 2 == 0)
//     {
//         for (int i = mid; i < n; i++)
//         {
//             arr[even] = A[i];
//             even += 2;
//         }

//         for (int j = mid - 1; j >= 0; j--)
//         {
//             arr[odd] = A[j];
//             odd += 2;
//         }
//     }

//     else
//     {
//         for (int i = mid + 1; i < n; i++)
//         {
//             arr[even] = A[i];
//             even += 2;
//         }

//         for (int j = mid; j >= 0; j--)
//         {
//             arr[odd] = A[j];
//             odd += 2;
//         }
//     }
// }



void Arange_array(int arr[], int n)
{
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = arr[i];
    }

    sort(A, n);
    int p = 0;
    int q = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            arr[i] = A[p];
            p++;
        }
        else
        {
            arr[i] = A[q];
            q--;
        }
    }
}

    int main()
    {
        // int arr[] = {1, 2, 1, 4, 5, 6, 8, 8};
        // int n = 8;

        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        int n = 7;
        Arange_array(arr, n);
        print(arr, n);
    }