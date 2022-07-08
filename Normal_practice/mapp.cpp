#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

// time complexity of unorder map    O(1)
// time complexity of ordered map/normal map  O(logn)

int main()
{
    unordered_map<string,int>m;

// insertion
pair<string,int>pair1 = make_pair("mera",1);
m.insert(pair1);

// insertion 2
pair<string,int>pair2{"name",2};
m.insert(pair2);

// insertion 3
m["chandu"] = 2;

// searching
cout<<"searching "<<endl;
cout<<m["chandu"]<<endl;
cout<<m["unknown"]<<endl;       // its give error if mapping is not present for perticular element
cout<<m.at("unknown")<<endl;    // its not give error if mapping is not present for any perticular element it is make the mapping

// size 
cout<<"size is"<<endl;
cout<<m.size()<<endl;

// to check present
cout<<"checking mapping is present or not"<<endl;
cout<<m.count("bro")<<endl;     // if not present return 0
cout<<m.count("chandu")<<endl;  // if present return 1


// erase
m.erase("chandu");
cout<<"after erase size is"<<endl;
cout<<m.size()<<endl;

// iterator
unordered_map<string,int> :: iterator it = m.begin();

while(it != m.end()){
    cout<<it->first <<" "<<it->second<<endl;
    it++;
}

}