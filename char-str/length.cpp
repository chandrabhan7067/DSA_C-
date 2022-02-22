#include <iostream>
#include <vector>

using namespace std;

int get_length(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char s[], int n)
{
    int st = 0;
    int e = n - 1;

    while (st <= e)
    {
        swap(s[st], s[e]);
        st++;
        e--;
    }
}

int main()
{
    char ch[20];
    cout << "Enter\n";
    cin >> ch;
    int n = get_length(ch);
    cout << "length is:" << n << endl;
    reverse(ch, n);
    cout << "reverse order is:" << ch;
}