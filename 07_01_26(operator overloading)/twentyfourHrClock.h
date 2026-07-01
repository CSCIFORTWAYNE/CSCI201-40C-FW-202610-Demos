#ifndef TWENTYFOUR_H
#define TWENTYFOUR_H
#include "clock.h"
class TwentyFourHrClock : public Clock
{
public:
    void setTime(int hour, int minute, int second);
    void incrementHours();
    Clock *copyClock() const;
    TwentyFourHrClock(int hr, int min, int sec = 0);
    friend void incrementClock(TwentyFourHrClock &);
    bool operator>(const TwentyFourHrClock &rightHandClock) const;
    friend bool operator<(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    TwentyFourHrClock operator+(int minutesToAdd);
    friend TwentyFourHrClock operator+(int minutesToAdd, TwentyFourHrClock clock);
};
#endif