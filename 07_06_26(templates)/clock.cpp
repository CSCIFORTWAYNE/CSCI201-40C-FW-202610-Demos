#include "clock.h"

/* const Clock::ClockType Clock::formats[2] = {Clock::TWELVE, Clock::TWENTYFOUR};
const Clock::PartOfDayType Clock::parts[2] = {Clock::AM, Clock::PM};
 */

void Clock::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Clock::setMinute(int m)
{
    if (m < 0 || m > 59)
    {
        m = 0;
    }
    min = m;
}
void Clock::setSecond(int s)
{
    if (s < 0 || s > 59)
    {
        s = 0;
    }
    sec = s;
}

void Clock::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

int Clock::getHour() const
{
    return hr;
}

int Clock::getMinute() const
{
    return min;
}

int Clock::getSecond() const
{
    return sec;
}

std::string Clock::printTime() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;

    // std::string out;
    // out = out + std::to_string(hr) + ":" + std::to_string(min) + ":" + std::to_string(sec);
    return out.str();
}

void Clock::incrementSeconds()
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        incrementMinutes();
    }
}

void Clock::incrementMinutes()
{
    min++;
    if (min == 60)
    {
        min = 0;
        incrementHours();
    }
}

/* bool Clock::equalTime(const Clock &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
} */

std::ostream &operator<<(std::ostream &out, const Clock &c)
{
    out << c.printTime();

    return out;
}
const Clock &Clock::operator++()
{
    incrementSeconds();
    return *this;
}
const Clock &Clock::operator++(int) // this will have a memory leak
{
    Clock *temp = makeCopy();
    incrementSeconds();
    return *temp;
}