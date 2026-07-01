#include "clock.h"

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
