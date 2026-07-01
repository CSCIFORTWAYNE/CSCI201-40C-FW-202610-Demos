#include "twentyfourHrClock.h"

Clock *TwentyFourHrClock::copyClock() const
{
    return new TwentyFourHrClock(*this);
}

void TwentyFourHrClock::incrementHours()
{
    hr = ++hr % 24;
}

void TwentyFourHrClock::setTime(int hr, int min, int sec)
{
    if (hr < 0)
    {
        hr = abs(hr);
    }

    if (hr >= 0 && hr <= 23)
    {
        this->hr = hr;
    }
    else
    {
        this->hr = hr % 24;
    }

    // can replace all if statements with hr = abs(hour) % 24;

    this->min = abs(min) % 60;
    this->sec = abs(sec) % 60;
}

TwentyFourHrClock::TwentyFourHrClock(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

void incrementClock(TwentyFourHrClock &clock)
{
    clock.min++;
}

bool TwentyFourHrClock::operator>(const TwentyFourHrClock &rightHandClock) const
{
    bool greaterThan = true;
    if (rightHandClock.hr > this->hr)
    {
        greaterThan = false;
    }
    else if (rightHandClock.hr == this->hr)
    {
        if (rightHandClock.min > this->min)
        {
            greaterThan = false;
        }
        else if (rightHandClock.min == this->min)
        {
            if (rightHandClock.sec >= this->sec)
            {
                greaterThan = false;
            }
        }
    }
    return greaterThan;
}

TwentyFourHrClock TwentyFourHrClock::operator+(int minutesToAdd)
{
    TwentyFourHrClock newClock = *this;
    for (int i = 0; i < minutesToAdd; i++)
    {
        newClock.incrementMinutes();
    }
    return newClock;
}

bool operator<(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    bool lessThan = true;
    if (rightHandClock.hr < leftHandClock.hr)
    {
        lessThan = false;
    }
    else if (rightHandClock.hr == leftHandClock.hr)
    {
        if (rightHandClock.min < leftHandClock.min)
        {
            lessThan = false;
        }
        else if (rightHandClock.min == leftHandClock.min)
        {
            if (rightHandClock.sec <= leftHandClock.sec)
            {
                lessThan = false;
            }
        }
    }
    return lessThan;
}

TwentyFourHrClock operator+(int minutesToAdd, TwentyFourHrClock clock)
{
    return clock + minutesToAdd;
}
