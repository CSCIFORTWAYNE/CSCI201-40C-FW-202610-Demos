#ifndef CLOCK_H
#define CLOCK_H
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
class Clock
{

public:
    virtual void setTime(int hour, int minute, int second) = 0;
    void getTime(int &hour, int &minute, int &second) const;
    virtual std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    virtual void incrementHours() = 0;
    bool equalTime(const Clock &otherClock) const;
    virtual Clock *copyClock() const = 0;

protected:
    int hr;
    int min;
    int sec;
};
#endif