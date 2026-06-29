#include "twentyfourHrClock.h"

Clock *TwentyFourHrClock::copyClock() const
{
    return new TwentyFourHrClock(*this);
}

void TwentyFourHrClock::incrementHours()
{
    hr = ++hr % 24;
}

void TwentyFourHrClock::setTime(int hour, int minute, int second)
{
    if (hour < 0)
    {
        hour = abs(hour);
    }

    if (hour >= 0 && hour <= 23)
    {
        hr = hour;
    }
    else
    {
        hr = hour % 24;
    }

    // can replace all if statements with hr = abs(hour) % 24;

    min = abs(minute) % 60;
    sec = abs(second) % 60;
}

TwentyFourHrClock::TwentyFourHrClock(int h, int m, int s)
{
    setTime(h, m, s);
}