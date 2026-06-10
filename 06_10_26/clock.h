#ifndef CLOCK_H
#define CLOCK_H
// #pragma once
#include <cmath>

class ClockType
{

public:
    void setTime(int hour, int minute, int second);
    void getTime(int &hour, int &minute, int &second) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType &otherClock) const;
    ClockType(int h, int m, int s);
    // ClockType();

private:
    int hr;
    int min;
    int sec;
};

#endif