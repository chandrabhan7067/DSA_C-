#include <iostream>
using namespace std;

char convertLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch - 'A' + 'a';
        return ch;
    }
    return ch;
}

int get_length(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool Palindrome(char arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (convertLower(arr[s]) != convertLower(arr[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

int main()
{
    char ch[20];
    cout << "Enter the string:\n";
    cin >> ch;
    int len = get_length(ch);
    if (Palindrome(ch, len))
    {
        cout << "Is palindrome ";
    }
    else
    {
        cout << "not palindorme";
    }
}