#include "movieTimes.h"

MovieTimes::MovieTimes(std::string t, int run, std::string rat)
{
    title = t;
    if (run <= 0)
    {
        run = 1;
    }
    runtime = run;
    rating = rat;
    showTimes = nullptr;
    numTimes = 0;
}
std::string MovieTimes::tostring() const
{
    std::ostringstream out;
    out << std::left;
    out << "| " << std::setw(40) << title << " | " << std::setw(5) << rating << " | " << std::setw(3) << runtime << " mins | ";
    for (int i = 0; i < numTimes; i++)
    {
        out << showTimes[i]->printTime() << " ";
    }
    return out.str();
}

std::string MovieTimes::getTitle() const
{
    return title;
}

int MovieTimes::getRuntime() const
{
    return runtime;
}

std::string MovieTimes::getRating() const
{
    return rating;
}

void MovieTimes::addTime(TwelveHrClock timeAdd)
{
    numTimes++;
    TwelveHrClock **temp = showTimes;
    showTimes = new TwelveHrClock *[numTimes];
    for (int i = 0; i < numTimes - 1; i++)
    {
        showTimes[i] = temp[i]; // acceptable shallow copy
    }
    showTimes[numTimes - 1] = new TwelveHrClock(timeAdd);
    delete[] temp;
}
