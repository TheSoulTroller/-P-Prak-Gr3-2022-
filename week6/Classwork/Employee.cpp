#include "employee.h"

void Employee::copy(const Employee& other)
{
    delete[] this->name;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->age = other.age;
    this->salary = other.salary;
}
void Employee::erase()
{
    delete[] this->name;
}

void Employee::setName(const char* name)
{
    try
    {
        if (strlen(name) == 0)
        {
            throw "Invalid name";
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    try
    {
        for (int i = 0; name[i] != '\0'; i++)
            if (name[i] >= '0' && name[i] <= '9')
            {
                throw "Name cannot contain numbers";
            }

        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
}
void Employee::setAge(int age)
{
    try
    {
        if(age <= 0)
        {
            throw "Invalid age";
        }	
        this->age = age;
    }
    catch(const char *msg)
    {
        cout << msg << endl;
    }
}
void Employee::setSalary(float salary)
{
    try
    {
        if (salary < 0)
            throw "Salary cannot be negative";
        this->salary = salary;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}

const char* Employee::getName() const
{
    return this->name;
}
int Employee::getAge() const
{
    return this->age;
}
float Employee::getSalary() const
{
    return this->salary;
}

Employee::Employee()
{
    setName("defaultName");
    setAge(1000);
    setSalary(0.0);
}

Employee::Employee(const char* name, int age, float salary)
{
    setName(name);
    setAge(age);
    setSalary(salary);
}

Employee::Employee(const Employee& other)
{   
    this->erase();
    this->copy(other);
}

Employee::~Employee()
{
    this->erase();
}

Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}