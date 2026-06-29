#include "person.h"
void Person::setAge(int a)
{
    if (a >= 0)
    {
        age = a;
    }
    else
    {
        age = 25;
    }
}

Person::Person(std::string n, int a, std::string p, std::string e)
{
    setAge(a);
    name = n;
    phone = p;
    email = e;
}

std::string Person::getName() const
{
    return name;
}

void Person::setName(std::string n)
{
    name = n;
}

int Person::getAge() const
{
    return age;
}

std::string Person::toString() const
{
    std::ostringstream out;
    out << "Name: " << name << std::endl;
    out << "Age: " << age << std::endl;
    out << "Phone: " << phone << std::endl;
    out << "Email: " << email << std::endl;
    return out.str();
}

std::string Person::getPhone() const
{
    return phone;
}

std::string Person::getEmail() const
{
    return email;
}

void Person::setPhone(std::string p)
{
    phone = p;
}

void Person::setEmail(std::string e)
{
    email = e;
}