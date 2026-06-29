#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <sstream>
#include "person.h"

class Employee : public Person
{
public:
    Employee();
    Employee(std::string n, int a, std::string p, std::string e, double s, std::string h);
    void setSalary(double s);
    void setHireDate(std::string h);
    double getSalary() const;
    std::string getHireDate() const;
    std::string toString() const;

private:
    double salary;
    std::string hireDate;
};

#endif