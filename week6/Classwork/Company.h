#pragma once

#include "employee.h"

class Company
{
private:
    Employee* employees;
    int size;
    int capacity = 10;

    void copy(const Company& other);
    void erase();
    void resize();

public:
    Company();
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    void addEmployee(const Employee& employee);	
    const Employee& getMostPaid() const;
    void saveWorkers(const char* filename);

    void print() const;

    int getSize() const;
    int getCapacity() const;
    Employee*& getEmployees() const;
};