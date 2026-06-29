#ifndef SHOW_H
#define SHOW_H
#include "twelveHrClock.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

class ShowTimes
{
public:
    ShowTimes(std::string title);
    ShowTimes(const ShowTimes &showToCopy);
    const ShowTimes &operator=(const ShowTimes &showToCopy);
    virtual std::string tostring() const;
    std::string getTitle() const;

    void addTime(const Clock &timeAdd);
    void clearTimes();
    virtual ~ShowTimes();

protected:
    std::string title;

    Clock **showTimes;
    int numTimes;
    void copyShow(const ShowTimes &showToCopy);
};
#endif