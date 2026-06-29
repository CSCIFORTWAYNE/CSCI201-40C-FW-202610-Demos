#ifndef CLOCK_H
#define CLOCK_H
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
class Clock
{

public:
    void setTime(int hour, int minute, int second);
    void getTime(int &hour, int &minute, int &second) const;
    virtual std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const Clock &otherClock) const;
    Clock(int hour, int minute, int second = 0);
    virtual Clock *copyClock() const;

protected:
    int hr;
    int min;
    int sec;
};
#endif