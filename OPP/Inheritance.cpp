#include <iostream>
using namespace std;

class Studnet
{

public:
    string name;
    int age;

public:
    void setname(string ch)
    {
        this->name = ch;
    }

    void setage(int a)
    {
        this->age = a;
    }

    void Details()
    {
        cout << "Age is:" << this->age << endl
             << "Name is: " << this->name;
    }
};

class Student1 : public Studnet
{
public:
    string color;

    void Details()
    {
        cout << "Age is:" << this->age << endl
             << "Name is: " << this->name << "Color is:" << endl
             << this->color;
    }
};

int main()
{
    Studnet object1;
    // object1.name = "Chandrabhan";
    // object1.age = 19;

    object1.setage(19);
    object1.setname("Chandrabhan");

    object1.Details();

    Student1 ob2;

    ob2.name = "Bahetwar";
    ob2.age = 19;
    ob2.color = "Red";

    ob2.Details();
}