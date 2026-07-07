#include "twentyFourHrClock.h"
#include "twelveHrClock.h"

TwentyFourHrClock::TwentyFourHrClock(int h, int m, int s)
{
    setTime(h, m, s);
}

void TwentyFourHrClock::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        hour = 0;
    }
    hr = hour;
}

void TwentyFourHrClock::incrementHours()
{
    hr++;
    if (hr == 24)
    {
        hr = 0;
    }
}

TwentyFourHrClock::TwentyFourHrClock(const TwelveHrClock &clockToConvert)
{
    int standardHr = clockToConvert.getHour();
    if (standardHr == 12)
    {
        standardHr = 0;
    }
    if (clockToConvert.getPartOfDayType() == TwelveHrClock::PM)
    {
        standardHr = standardHr + 12;
    }
    hr = standardHr;
    min = clockToConvert.getMinute();
    sec = clockToConvert.getSecond();
}

TwentyFourHrClock TwentyFourHrClock::operator+(int minutesToAdd)
{
    TwentyFourHrClock newClock = *this;
    for (int i = 0; i < minutesToAdd; i++)
    {
        newClock.incrementMinutes();
    }
    return newClock;
}

bool TwentyFourHrClock::operator==(TwentyFourHrClock rightClock)
{
    return this->hr == rightClock.hr && this->min == rightClock.min && this->sec == rightClock.sec;
}

/* bool operator==(TwentyFourHrClock leftClock, TwentyFourHrClock rightClock)
{
    return leftClock.hr == rightClock.hr && leftClock.min == rightClock.min && leftClock.sec == rightClock.sec;
} */

bool TwentyFourHrClock::operator!=(TwentyFourHrClock rightClock)
{
    return !(*this == rightClock);
}

Clock *TwentyFourHrClock::makeCopy()
{
    return new TwentyFourHrClock(*this);
}

TwentyFourHrClock operator+(int minutesToAdd, TwentyFourHrClock c)
{
    return c + minutesToAdd;
}

std::istream &operator>>(std::istream &in, TwelveHrClock &c)
{
    int h, m, s;
    in >> h >> m >> s;
    c.setHour(h);
    c.setMinute(m);
    c.setSecond(s);
    return in;
}
