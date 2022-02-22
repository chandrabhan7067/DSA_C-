#include <iostream>
using namespace std;

bool remove_non_alphanumeric(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char convertLower(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        ch = ch - 'A' + 'a';
        return ch;
    }
}

bool check_palindrome(string st)
{
    int s = 0;
    int e = st.length() - 1;

    while (s <= e)
    {
        if (st[s] != st[e])
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
    string st = "A man, a plan, a canal: Panama";
    // string st = "race a car";
    string temp = "";

    //  remove all alphanumeric

    for (int i = 0; i < st.length(); i++)
    {
        if (remove_non_alphanumeric(st[i]))
        {
            temp.push_back(st[i]);
        }
    }

    //  convert all the element to lower case

    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = convertLower(temp[i]);
    }

    // cout<<temp;
    if (check_palindrome(temp))
    {
        cout << "Yes";
    }
    else
    {
        cout << "no";
    }
}