#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int salary;

    void Print_details()
    {
        cout << "name of the employee is " << this->name << " and salary is :" << this->salary;
    }
};

int main()
{
    Employee cha;
    cha.name = "chandrabhan";
    cha.salary = 2394;
    cout<<"name is:"<<cha.name<< " salary is: "<<cha.salary;
    // cha.Print_details();
}