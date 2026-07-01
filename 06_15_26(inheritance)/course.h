#ifndef COURSE_H
#define COURSE_H
#include "room.h"
#include "twelveHrClock.h"
#include <string>
class Course
{
public:
    Course(std::string d, int cn, std::string s, char days[], int nd, TwelveHrClock st, TwelveHrClock et, Room r);
    // getters for all data
    // setters for all data except section courseNum and department
    // tostring
private:
    std::string dept;
    int courseNum;
    std::string section;
    char meetingDays[4];
    int numDays;
    TwelveHrClock startTime;
    TwelveHrClock endTime;
    Room classroom;
};

#endif