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
MovieTimes::MovieTimes(const MovieTimes &movieToCopy)
{
    numTimes = 0;
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

void MovieTimes::addTime(const Clock &timeAdd)
{
    numTimes++;
    Clock **temp = showTimes;
    showTimes = new Clock *[numTimes];
    for (int i = 0; i < numTimes - 1; i++)
    {
        showTimes[i] = temp[i]; // acceptable shallow copy
    }
    showTimes[numTimes - 1] = timeAdd.copyClock();
    delete[] temp;
}

void MovieTimes::clearTimes()
{
    for (int i = 0; i < numTimes; i++)
    {
        delete showTimes[i];
    }
    delete[] showTimes;
    showTimes = nullptr;
}

MovieTimes::~MovieTimes()
{
    clearTimes();
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
