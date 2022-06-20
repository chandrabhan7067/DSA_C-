#include<iostream>
#include<map>
using namespace std;

// two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 

bool isIsomorphic(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }

    map<char,char>map1;
    map<char,bool>map2;

    for (int i = 0; i < str1.size(); i++)
    {
        if(map1.find(str1[i]) == map1.end()){
            if(map2[str2[i]] == true){
                return false;
            }
            else{
                map1[str1[i]] = str2[i];
                map2[str2[i]] = true;
            }
        }

        else{
            if(map1[str1[i]] != str2[i]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string str1 = "aabbc";
    string str2 = "xyxyz";
    cout<<isIsomorphic(str1,str2);
}