#include <iostream>
using namespace std;

class Student1
{
public:
    int name;

    void Speak()
    {
        cout << "speacking"<<endl;
    }
};

class Student2
{
public:
    int age;

    void Speak_second()
    {
        cout << "speacking second"<<endl;
    }
};

class Student3 : public Student1, public Student2
{
    int name;
};

int main()
{
    Student3 ob;
    ob.Speak();
    ob.Speak_second();
}
