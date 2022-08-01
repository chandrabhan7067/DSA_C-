#include<iostream>
#include<limits.h>
using namespace std;

// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

// for example 001 there are only two cases   101 or  010  so we are checking both the cases  using variable zero and one

int minFlips(string s){
    char zero = '0', one = '1';
    int a = 0, b = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == zero){
            b++;
        }

        if(s[i] == one){
            a++;
        }
        swap(zero,one);
    }

    return min(a,b);
    
}

int main()
{
    string s = "0001010111";
    cout<<minFlips(s);

}