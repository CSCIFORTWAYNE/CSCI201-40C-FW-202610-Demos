#ifndef TFCLOCK_H
#define TFCLOCK_H
#include <string>
#include <sstream>
#include <iomanip>
#include "clock.h"
class TwelveHrClock;
class TwentyFourHrClock : public Clock
{
public:
    TwentyFourHrClock(int h = 0, int m = 0, int s = 0);
    TwentyFourHrClock(const TwelveHrClock &);
    void setHour(int hour);
    void incrementHours();
    TwentyFourHrClock operator+(int minutesToAdd);
    friend TwentyFourHrClock operator+(int minutesToAdd, TwentyFourHrClock c); // minutesToAdd is the left operand, the clock is the right operand.
    bool operator==(TwentyFourHrClock rightClock);
    // friend bool operator==(TwentyFourHrClock leftClock, TwentyFourHrClock rightClock);
    bool operator!=(TwentyFourHrClock rightClock);
    Clock *makeCopy();
    // add operators for <, <=, >, >= either friend or member
    friend std::istream &operator>>(std::istream &in, TwelveHrClock &c);
};

#endif
