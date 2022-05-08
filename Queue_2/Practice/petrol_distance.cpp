#include <iostream>
using namespace std;

int solve(int petrol[], int distance[], int n)
{
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j = (j + 1) % n)
        {
            balance += petrol[j] - distance[j];

            if (balance < 0)
            {
                start = i + 1;
                balance = 0;
                break;
            }

            if (j == start)
            {
                return start;
            }
        }
    }
}

int main()
{
    // int petrol[] = {4,6,3,5};
    int petrol[] = {6, 7, 4, 10, 6, 5};
    // int distance[] = {6,5,3,5};
    int distance[] = {5, 6, 7, 8, 6, 4};

    cout << solve(petrol, distance, 6);
}