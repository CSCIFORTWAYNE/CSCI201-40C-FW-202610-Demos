#include <iostream>
#include <string>
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

int main()
{
    Car c;
}