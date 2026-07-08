#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "clockExcept.h"

class Clock
{
public:
    /* enum ClockType
    {
        TWELVE,
        TWENTYFOUR
    };
    enum PartOfDayType
    {
        AM,
        PM
    }; */
    // Clock(int, int, int, ClockType = TWENTYFOUR, PartOfDayType = AM);
    virtual void setTime(int, int = 0, int = 0);
    virtual void setHour(int) = 0;
    void setMinute(int);
    void setSecond(int);
    void getTime(int &, int &, int &) const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    virtual std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    virtual void incrementHours() = 0;
    virtual Clock *makeCopy() = 0;
    friend std::ostream &operator<<(std::ostream &, const Clock &);
    const Clock &operator++();
    const Clock &operator++(int);
    // bool equalTime(const Clock &) const;
    // void clockTick();
    // static const ClockType formats[2];   // = {TWELVE, TWENTYFOUR};
    // static const PartOfDayType parts[2]; //{partType::AM, partType::PM};

protected:
    int hr;
    int min;
    int sec;
    // ClockType type;
    //  PartOfDayType timeOfDay;
};

#endif