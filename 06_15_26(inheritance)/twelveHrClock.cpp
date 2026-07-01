#include "twelveHrClock.h"

std::string TwelveHrClock::printTime()
{
    std::ostringstream out;
    out << Clock::printTime() << " ";
    for (int i = 0; i < 2; i++)
    {
        if (partOfDay == parts[i])
        {
            out << partToStr[i];
        }
    }

    return out.str();
}

void TwelveHrClock::setTime(int hour, int minute, int second)
{
    hour = abs(hour);
    if (hour < 1 || hour > 12)
    {
        hour = hour % 12;
    }
    if (hour == 0)
    {
        hour = 12;
    }
    Clock::setTime(hour, minute, second);
}

TwelveHrClock::TwelveHrClock(int hour, int minute, int second, partOfDayType part) : Clock(hour, minute, second)
{
    if (!validHour())
    {
        setTime(hour, minute, second);
    }
    partOfDay = part;
}

bool TwelveHrClock::validHour()
{
    return hr >= 1 && hr <= 12;
}

TwelveHrClock::partOfDayType TwelveHrClock::parts[2] = {
    partOfDayType::AM,
    partOfDayType::PM};
std::string TwelveHrClock::partToStr[2] = {"AM", "PM"};