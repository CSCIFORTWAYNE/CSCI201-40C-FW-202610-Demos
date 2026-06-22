#include "clock.h"

void Clock::setTime(int hour, int minute, int second)
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

bool Clock::equalTime(const Clock &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}

void Clock::getTime(int &hour, int &minute, int &second) const
{
    hour = hr;
    minute = min;
    second = sec;
}

void Clock::incrementHours()
{
    hr = ++hr % 24;
}

std::string Clock::printTime() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;

    return out.str();
}

void Clock::incrementSeconds()
{
    sec = ++sec % 60;
}

void Clock::incrementMinutes()
{
    min = ++min % 60;
}

Clock::Clock(int h, int m, int s) //: hr(h), min(m), sec(s) initializes the members to the parameters. Shouldn't be used if the data needs validated
{
    setTime(h, m, s);
}
