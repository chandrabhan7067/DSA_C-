#include <iostream>
using namespace std;

int len_new_array(char ch[])
{
    int n = sizeof(ch) / sizeof(ch[0]);
    int i = 0;
    int ansIndex = 0;

    while (i < n)
    {
        int j = i + 1;

        while (j < n && ch[i] == ch[j])
        {
            j++;
        }
        ch[ansIndex] = ch[i];
        ansIndex++;
        int count = j - i;

        if (count > 1)
        {
            string convert = to_string(count);
            for (char c : convert)
            {
                ch[ansIndex] = c;
                ansIndex++;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    char ch[] = "aabbccc";
    cout << len_new_array(ch);
}