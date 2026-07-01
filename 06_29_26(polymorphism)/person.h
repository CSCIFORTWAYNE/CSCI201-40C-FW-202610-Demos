#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <sstream>

class Person
{
public:
    Person(std::string n, int a, std::string p, std::string e);

    std::string getName() const;
    void setName(std::string name);
    int getAge() const;
    void setAge(int a);
    virtual std::string toString() const;
    std::string getPhone() const;
    std::string getEmail() const;
    void setPhone(std::string p);
    void setEmail(std::string e);

protected:
    int age;
    std::string name;
    std::string phone;
    std::string email;
};

#endif