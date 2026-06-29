#include "movieTimes.h"

MovieTimes::MovieTimes(std::string t, int run, std::string rat) : ShowTimes(t)
{

    if (run <= 0)
    {
        run = 1;
    }
    runtime = run;
    rating = rat;
    dynamicData = new int(7);
}
MovieTimes::MovieTimes(const MovieTimes &movieToCopy) : ShowTimes(movieToCopy.title)
{
    numTimes = 0;
    dynamicData = new int(7);
    copyMovie(movieToCopy);
}
const MovieTimes &MovieTimes::operator=(const MovieTimes &movieToCopy)
{
    if (this != &movieToCopy)
    {
        copyMovie(movieToCopy);
    }
    return *this;
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

int MovieTimes::getRuntime() const
{
    return runtime;
}

std::string MovieTimes::getRating() const
{
    return rating;
}

MovieTimes::~MovieTimes()
{

    delete dynamicData;
}

void MovieTimes::copyMovie(const MovieTimes &movieToCopy)
{
    title = movieToCopy.title;
    runtime = movieToCopy.runtime;
    rating = movieToCopy.rating;
    if (numTimes > 0)
    {
        clearTimes();
    }
    numTimes = movieToCopy.numTimes;
    showTimes = new Clock *[numTimes];
    for (int i = 0; i < numTimes; i++)
    {
        // showTimes[i] = movieToCopy.showTimes[i]; //bad shallow copy
        showTimes[i] = movieToCopy.showTimes[i]->copyClock();
    }
}
