#include "twelveHrClock.h"
#include "twentyFourHrClock.h"

const TwelveHrClock::PartOfDayType TwelveHrClock::parts[2] = {TwelveHrClock::AM, TwelveHrClock::PM};
const std::string TwelveHrClock::partToStr[] = {"AM", "PM"};
std::map<TwelveHrClock::PartOfDayType, std::string> TwelveHrClock::partToStrMap = {{TwelveHrClock::AM, "AM"}, {TwelveHrClock::PM, "PM"}};
std::map<std::string, TwelveHrClock::PartOfDayType> TwelveHrClock::strToPartMap = {{"AM", TwelveHrClock::AM}, {"am", TwelveHrClock::AM}, {"PM", TwelveHrClock::PM}, {"pm", TwelveHrClock::PM}};

TwelveHrClock::TwelveHrClock(int h, int m, int s, PartOfDayType part)
{
    setTime(h, m, s);
    setPartOfDay(part);
}

TwelveHrClock::TwelveHrClock(const TwentyFourHrClock &clockToConvert)
{
    int newHour = clockToConvert.getHour();
    if (newHour >= 12)
    {
        partOfDay = PM;
    }
    if (newHour > 12)
    {
        newHour = newHour - 12;
    }
    hr = newHour;
    min = clockToConvert.getMinute();
    sec = clockToConvert.getSecond();
}

void TwelveHrClock::setHour(int hour)
{

    if (hour < 1 || hour > 12)
    {
        hour = 12;
    }

    hr = hour;
}

void TwelveHrClock::incrementHours()
{
    hr++;
    if (hr == 12)
    {
        if (partOfDay == TwelveHrClock::AM)
        {
            partOfDay = TwelveHrClock::PM;
        }
        else
        {
            partOfDay = TwelveHrClock::AM;
        }
    }

    if (hr > 12)
    {
        hr = 1;
    }
}

void TwelveHrClock::setPartOfDay(PartOfDayType part)
{
    partOfDay = part;
}

std::string TwelveHrClock::getPartOfDayStr() const
{
    return partToStrMap[partOfDay];
}

TwelveHrClock::PartOfDayType TwelveHrClock::getPartOfDayType() const
{
    return partOfDay;
}

std::string TwelveHrClock::printTime() const
{
    std::string out = Clock::printTime() + " " + getPartOfDayStr();
    return out;
}

/* bool operator==(TwelveHrClock leftClock, TwelveHrClock rightClock)
{
    return leftClock.partOfDay == rightClock.partOfDay && leftClock.hr == rightClock.hr && leftClock.min == rightClock.min && leftClock.sec == rightClock.sec;
} */
bool TwelveHrClock::operator==(TwelveHrClock rightClock)
{
    return this->partOfDay == rightClock.partOfDay && this->hr == rightClock.hr && this->min == rightClock.min && this->sec == rightClock.sec;
}

Clock *TwelveHrClock::makeCopy()
{
    return new TwelveHrClock(*this);
}
