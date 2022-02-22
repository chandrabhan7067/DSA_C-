#include <iostream>
using namespace std;

class Person
{
    char name;
    int age;

public:
    char getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void setName(char Name)
    {
        name = Name;
    }

    void setAge(int Age)
    {
        age = Age;
    }

    void Print()
    {
        cout << "Name is:" << name << endl;
    }
};

int main()
{
    Person ob;
    // ob.name = 'C';
    // ob.age = 80;
    // cout<<"Name is:"<<ob.name<<endl;
    // cout<<"age is:"<<ob.age<<endl;

    cout << sizeof(ob) << endl;
    ob.setName('C');
    ob.setAge(20);
    cout << "name is:" << ob.getName() << endl;
    cout << "age is:" << ob.getAge() << endl;


    // Dynamiclly create a object

    Person *p = new Person;
    p->setName('A');
    p->setAge(10);
    cout << "name is:" << p->getName() << endl;
    cout << "age is:" << (*p).getAge() << endl;
}