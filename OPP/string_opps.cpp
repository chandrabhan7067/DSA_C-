#include<iostream>
using namespace std;

class Student{
    public:
        string name;

        Student(string name){
            this->name = name;
        }

        void print(){
            cout<<"Name is:"<<name;
        }


};

int main()
{
    Student ob("Chan");
    // ob.name = "Chan";
    // ob.print();
    cout<<ob.name;
}