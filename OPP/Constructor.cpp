#include<iostream>
using namespace std;

class Person{
    public:
    char name;
    int age;

    Person(){
        cout<<"Constructer is called"<<endl;
    }

    Person(char Name){
        this->name = Name;
    }

    Person(char Name,int age){
        this->name = Name;
        this->age = age;
    }

    void print(){
        cout<<this->name<<endl;
        cout<<this->age<<endl;
    }
};

int main(){
    Person ob('c');
    // cout<<ob.name;
    ob.print();

    Person temp('B',19);
    temp.print();

    Person *p = new Person('D',21);
    p->print();
    
}