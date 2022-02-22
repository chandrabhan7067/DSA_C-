#include <iostream>
using namespace std;

char convertLower(char ch)
{
    if (ch > 'A' && ch < 'Z')
    {
        ch = ch - 'A' + 'a';
        return ch;
    }
    return ch;
}

char convertUper(char ch)
{
    if (ch > 'a' && ch < 'z')
    {
        ch = ch - 'a' + 'A';
        return ch;
    }
    return ch;
}

int main()
{
    char ch = 'B';
    char ch1 = 'c';
    cout << "lower case is:" << convertLower(ch) << endl;
    cout << "Uper case is:" << convertUper(ch1) << endl;

    // convert charcter to integer
    char n1 = '1';
    int convert = n1 - '0';
    cout << convert;
}