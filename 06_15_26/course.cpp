#include "course.h"

Course::Course(std::string d, int cn, std::string s, char days[], int nd, TwelveHrClock st, TwelveHrClock et, Room r) : startTime(st), endTime(et), classroom(r) // invoking the copy constructor to create the clocks and room
{
    dept = d;
    courseNum = abs(cn);
    section = s;
    numDays = nd;
    for (int i = 0; i < nd; i++)
    {
        meetingDays[i] = days[i];
    }
}