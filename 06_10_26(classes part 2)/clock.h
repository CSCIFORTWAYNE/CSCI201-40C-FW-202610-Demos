#ifndef CLOCK_H
#define CLOCK_H
// #pragma once
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

class ClockType
{

public:
    enum class partOfDayType
    {
        AM,
        PM
    };
    enum class formatType
    {
        TWELVE,
        TWENTYFOUR
    };
    void setTime(int hour, int minute, int second);
    void getTime(int &hour, int &minute, int &second) const;
    std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType &otherClock) const;
    ClockType(int h, int m, int s, formatType = formatType::TWENTYFOUR, partOfDayType = partOfDayType::AM);
    // ClockType();
    static partOfDayType parts[2]; /*  = {
         partofDayType::AM,
         partofDayType::PM
     }; */
    static std::string partToStr[2];
    static formatType formats[2];

private:
    int hr;
    int min;
    int sec;
    formatType format;
    partOfDayType partOfDay;
};

#endif