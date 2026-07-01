#ifndef MOVIE_H
#define MOVIE_H
#include "twelveHrClock.h"
#include "showTimes.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

class MovieTimes : public ShowTimes
{
public:
    MovieTimes(std::string title, int runtime, std::string rating);
    MovieTimes(const MovieTimes &movieToCopy);
    const MovieTimes &operator=(const MovieTimes &movieToCopy);
    std::string tostring() const;

    int getRuntime() const;
    std::string getRating() const;

    ~MovieTimes();

private:
    int runtime;
    std::string rating;
    int *dynamicData;
    void copyMovie(const MovieTimes &movieToCopy);
};
#endif