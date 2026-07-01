#ifndef TWELVE_H
#define TWELVE_H
#include "clock.h"

class TwelveHrClock : public Clock
{
public:
    enum class partOfDayType
    {
        AM,
        PM
    };
    std::string printTime();
    void setTime(int hour, int minute, int second);
    TwelveHrClock(int hour, int minute, partOfDayType part, int second = 0);
    static partOfDayType parts[2]; /*  = {
         partofDayType::AM,
         partofDayType::PM
     }; */
    static std::string partToStr[2];

private:
    bool validHour();
    partOfDayType partOfDay;
};

#endif