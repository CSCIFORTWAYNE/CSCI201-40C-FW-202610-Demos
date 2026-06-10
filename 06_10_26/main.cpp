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

int main()
{
    int nums[50];
    // ClockType clocks[50];
    ClockType c(0, 0, 0);
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
