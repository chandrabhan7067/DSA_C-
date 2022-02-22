#include <iostream>
using namespace std;

int Getlenght(char ch[])
{
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char ch[], int len)
{
    int s = 0;
    int e = len - 1;

    while (s <= e)
    {
        swap(ch[s], ch[e]);
        s++;
        e--;
    }
}

int main()
{
    char ch[20];
    cout << "Enter\n";
    cin >> ch;
    int len = Getlenght(ch);
    reverse(ch, len);
    cout << ch;
}