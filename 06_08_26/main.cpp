#include <iostream>
#include <string>
#include <cmath>

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
};

class ClockType
{

public:
    void setTime(int hour, int minute, int second);
    void getTime(int &hour, int &minute, int &second) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType &otherClock) const;

private:
    int hr;
    int min;
    int sec;
};

int main()
{
    Car c;
    // c.make = "honda";
    std::cout << "hello world" << std::endl;
    return 0;
}

void ClockType::setTime(int hour, int minute, int second)
{
    if (hour < 0)
    {
        hour = abs(hour);
    }

    if (hour >= 0 && hour <= 23)
    {
        hr = hour;
    }
    else
    {
        hr = hour % 24;
    }
    // can replace all if statements with hr = abs(hour) % 24;

    min = abs(minute) % 60;
    sec = abs(second) % 60;
}