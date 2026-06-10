#include "clock.h"

void ClockType::setTime(int hour, int minute, int second)
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

bool ClockType::equalTime(const ClockType &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}

void ClockType::getTime(int &hour, int &minute, int &second) const
{
    hour = hr;
    minute = min;
    second = sec;
}

void ClockType::incrementHours()
{
    hr = ++hr % 24;
}