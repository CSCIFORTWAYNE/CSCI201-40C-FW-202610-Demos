#ifndef TCLOCK_H
#define TCLOCK_H
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include "clock.h"

class TwentyFourHrClock;
class TwelveHrClock : public Clock
{
public:
    enum PartOfDayType
    {
        AM = 18,
        PM = 56
    };
    static const PartOfDayType parts[2]; //{partType::AM, partType::PM};
    static const std::string partToStr[2];
    static std::map<PartOfDayType, std::string> partToStrMap;
    static std::map<std::string, PartOfDayType> strToPartMap;
    TwelveHrClock(int h = 12, int m = 0, int s = 0, PartOfDayType part = AM);
    TwelveHrClock(const TwentyFourHrClock &clockToConvert);
    void setHour(int hour);
    void incrementHours();
    void setPartOfDay(PartOfDayType part);
    std::string getPartOfDayStr() const;
    PartOfDayType getPartOfDayType() const;
    std::string printTime() const;
    // friend bool operator==(TwelveHrClock leftClock, TwelveHrClock rightClock);
    bool operator==(TwelveHrClock rightClock);
    Clock *makeCopy();

private:
    PartOfDayType partOfDay;
};

#endif