#ifndef TWENTYFOUR_H
#define TWENTYFOUR_H
#include "clock.h"
class TwentyFourHrClock : public Clock
{
public:
    void setTime(int hour, int minute, int second);
    void incrementHours();
    Clock *copyClock() const;
    TwentyFourHrClock(int hour, int minute, int second = 0);
};
#endif