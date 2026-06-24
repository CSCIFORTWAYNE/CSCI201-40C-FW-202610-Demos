#ifndef MOVIE_H
#define MOVIE_H
#include "twelveHrClock.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

class MovieTimes
{
public:
    MovieTimes(std::string title, int runtime, std::string rating);
    std::string tostring() const;
    std::string getTitle() const;
    int getRuntime() const;
    std::string getRating() const;
    void addTime(TwelveHrClock timeAdd);

private:
    std::string title;
    int runtime;
    std::string rating;
    TwelveHrClock **showTimes;
    int numTimes;
};
#endif