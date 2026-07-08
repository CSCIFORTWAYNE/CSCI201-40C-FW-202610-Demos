#include "clockExcept.h"

Invalid_Hour::Invalid_Hour() : invalid_argument("The hour given is invalid.")
{
    hour = -1;
    low = -1;
    high = -1;
}

Invalid_Hour::Invalid_Hour(int hour, int low, int high) : invalid_argument("The hour (" + std::to_string(hour) + ") is invalid.")
{
    this->hour = hour;
    this->low = low;
    this->high = high;
}

int Invalid_Hour::getHour() const
{
    return hour;
}

void Invalid_Hour::getHourRange(int &low, int &high) const
{
    low = this->low;
    high = this->high;
}

Invalid_Minute::Invalid_Minute() : std::invalid_argument("The minute given is invalid")
{
    minute = -1;
}

Invalid_Minute::Invalid_Minute(int minute) : std::invalid_argument("The minute (" + std::to_string(minute) + ") is invalid.")
{
    this->minute = minute;
}

int Invalid_Minute::getMinute() const
{
    return minute;
}

Invalid_Second::Invalid_Second() : std::invalid_argument("The seconds given are invalid.")
{
    second = -1;
}

Invalid_Second::Invalid_Second(int second) : std::invalid_argument("The second (" + std::to_string(second) + ") is invalid.")
{
    this->second = second;
}

int Invalid_Second::getSecond() const
{
    return second;
}
