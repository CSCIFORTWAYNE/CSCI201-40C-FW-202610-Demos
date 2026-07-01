#include <iostream>
#include <string>
#include <cstdlib>
#include "clock.h"

class Car
{

    std::string make;
    std::string model;
    int year;
    long mileage;
    std::string color;
    double GVWR; // gross vehicle weight rating
    bool started;

public:
    void startCar();
    Car(std::string ma = "Ford", std::string mo = "F150", int y = 2026, long mi = 0, std::string co = "Black", double gv = 5000);
};

void myFunc(ClockType &theClock);
int getClockHour(ClockType::formatType format);
int getClockMinute();
int getClockSecond();
ClockType::formatType getClockFormat();
void resetStream();

int main()
{
    int nums[50];
    // ClockType clocks[50];
    ClockType c(0, 0, 0, ClockType::formatType::TWELVE, ClockType::partOfDayType::PM);
    for (int i = 0; i < rand() % 20 + 1; i++)
    {
        myFunc(c);
    }
}

void myFunc(ClockType &theClock)
{
    static int numMinutes = 0;
    theClock.incrementMinutes();
    numMinutes++;
    std::cout << "The clock has advanced " << numMinutes << " minutes." << std::endl;
}

int getClockHour(ClockType::formatType format)
{
    int hour;
    std::cout << "Enter the clock hour:";
    std::cin >> hour;
    while (!std::cin || (format == ClockType::formatType::TWELVE && (hour < 1 || hour > 12)) || (format == ClockType::formatType::TWENTYFOUR && (hour < 0 || hour > 23)))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid hour." << std::endl;
        if (format == ClockType::formatType::TWENTYFOUR)
        {
            std::cout << "Valid hours are between 0 and 23" << std::endl;
        }
        else
        {
            std::cout << "Valid hours are between 1 and 12" << std::endl;
        }
        std::cout << "Enter the clock hour:";
        std::cin >> hour;
    }
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
