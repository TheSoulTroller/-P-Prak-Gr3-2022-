#include "Company.h"

int main()
{
    Company company;
    company.addEmployee(Employee("John", 26, 15000));
    company.addEmployee(Employee("Jane", 25, 12000));
    company.addEmployee(Employee("Jack", 27, 18000));
    company.addEmployee(Employee("Jill", 24, 13000));
    company.addEmployee(Employee("Joe", 28, 19000));
    company.addEmployee(Employee("Jenny", 29, 20000));
    company.saveWorkers("workers.txt");

    return 0;
}