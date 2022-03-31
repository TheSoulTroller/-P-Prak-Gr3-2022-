#include "Company.h"

void Company::copy(const Company& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->employees = new Employee[this->capacity];
    for(int i = 0; i < size; i++){
        this->employees[i] = other.employees[i];
    }
}
void Company::erase()
{
    delete[] this->employees;
}
void Company::resize()
{
    this->capacity *= 2;
    Employee* temp = new Employee[this->capacity];
    for(int i = 0; i < this->size; i++){
        temp[i] = this->employees[i];
    }
    delete[] this->employees;
    this->employees = temp;
}

int Company::getSize() const
{
    return this->size;
}
int Company::getCapacity() const
{
    return this->capacity;
}

Company::Company()
{
    this->employees = new Employee[this->capacity];
    this->size = 0;
}
Company::Company(const Company &other)
{
    this->copy(other);
}
Company &Company::operator=(const Company &other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
Company::~Company()
{
    this->erase();
}

void Company::addEmployee(const Employee &employee)
{
    if(size >= capacity) resize();
    this->employees[size] = employee;
    this->size++;
}
void Company::saveWorkers(const char* filename)
{
    std::ofstream out(filename, std::ios::app);
    for(int i = 0; i < this->size; i++){
        out << "\nName: " << this->employees[i].getName();
        out << "\nAge: " << this->employees[i].getAge();
        out << "\nSalary: " << this->employees[i].getSalary();
        out << "\n_________________________________________";
    }
    out.close();
}

