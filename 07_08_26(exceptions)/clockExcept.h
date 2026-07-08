#ifndef CLOCKE_H
#define CLOCKE_H
#include <stdexcept>

class Invalid_Hour : public std::invalid_argument
{
public:
    Invalid_Hour();
    Invalid_Hour(int, int, int);
    int getHour() const;
    void getHourRange(int &, int &) const;

private:
    int hour;
    int low;
    int high;
};
class Invalid_Minute : public std::invalid_argument
{
public:
    Invalid_Minute();
    Invalid_Minute(int);
    int getMinute() const;

private:
    int minute;
};
class Invalid_Second : public std::invalid_argument
{
public:
    Invalid_Second();
    Invalid_Second(int);
    int getSecond() const;

private:
    int second;
};

#endif