#include "showTimes.h"

ShowTimes::ShowTimes(std::string t)
{
    title = t;

    showTimes = nullptr;
    numTimes = 0;
}
ShowTimes::ShowTimes(const ShowTimes &showToCopy)
{
    numTimes = 0;
    copyShow(showToCopy);
}
const ShowTimes &ShowTimes::operator=(const ShowTimes &showToCopy)
{
    if (this != &showToCopy)
    {
        copyShow(showToCopy);
    }
    return *this;
}
std::string ShowTimes::tostring() const
{
    std::ostringstream out;
    out << std::left;
    out << "| " << std::setw(40) << title << " | ";
    for (int i = 0; i < numTimes; i++)
    {
        out << showTimes[i]->printTime() << " ";
    }
    return out.str();
}

std::string ShowTimes::getTitle() const
{
    return title;
}

void ShowTimes::addTime(const Clock &timeAdd)
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

void ShowTimes::clearTimes()
{
    for (int i = 0; i < numTimes; i++)
    {
        delete showTimes[i];
    }
    delete[] showTimes;
    showTimes = nullptr;
}

ShowTimes::~ShowTimes()
{
    clearTimes();
}

void ShowTimes::copyShow(const ShowTimes &showToCopy)
{
    title = showToCopy.title;

    if (numTimes > 0)
    {
        clearTimes();
    }
    numTimes = showToCopy.numTimes;
    showTimes = new Clock *[numTimes];
    for (int i = 0; i < numTimes; i++)
    {
        // showTimes[i] = showToCopy.showTimes[i]; //bad shallow copy
        showTimes[i] = showToCopy.showTimes[i]->copyClock();
    }
}
