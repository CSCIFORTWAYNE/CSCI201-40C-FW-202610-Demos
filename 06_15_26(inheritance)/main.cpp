#include "twelveHrClock.h"
#include "clock.h"
#include <iostream>
// Module 2A(a): In-Class Activity Submission
// implement the room class based on the room.h header file
// submit your room.cpp to IvyLearn
int main()
{
    TwelveHrClock c(2, 3, 3, TwelveHrClock::partOfDayType::AM);
    Clock c1(13, 2, 2);
    // c.setTime(2, 3, 3);
    std::cout << c.printTime() << std::endl;
    return 0;
}