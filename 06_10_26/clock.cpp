#include "clock.h"

void ClockType::setTime(int hour, int minute, int second)
{
    if (hour < 0)
    {
        hour = abs(hour);
    }
    if (format == formatType::TWENTYFOUR)
    {
        if (hour >= 0 && hour <= 23)
        {
            hr = hour;
        }
        else
        {
            hr = hour % 24;
        }
    }
    else
    {
        if (hour >= 1 && hour <= 12)
        {
            hr = hour;
        }
        else
        {
            hr = hour % 12 + 1;
        }
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

std::string ClockType::printTime() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    if (format == formatType::TWELVE)
    {
        for (int i = 0; i < 2; i++)
        {
            if (partOfDay == parts[i])
            {
                out << " " << partToStr[i];
            }
        }
        // out << " " << partToStr[static_cast<int>(partOfDay)];
    }
    return std::string();
}

void ClockType::incrementSeconds()
{
    sec = ++sec % 60;
}

void ClockType::incrementMinutes()
{
    min = ++min % 60;
}

ClockType::ClockType(int h, int m, int s, formatType f, partOfDayType p) : format(f), partOfDay(p) //: hr(h), min(m), sec(s) initializes the members to the parameters. Shouldn't be used if the data needs validated
{
    setTime(h, m, s);
}

ClockType::partOfDayType ClockType::parts[2] = {
    partOfDayType::AM,
    partOfDayType::PM};
std::string ClockType::partToStr[2] = {"AM", "PM"};
ClockType::formatType ClockType::formats[2] = {formatType::TWELVE,
                                               formatType::TWENTYFOUR};
