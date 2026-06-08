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
    Car(std::string ma, std::string mo, int y, long mi, std::string co, double gv);
    Car();
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
    Car myCar("Honda", "HRV", 2018, 40000, "Green", 830);
    ClockType myClock;
    ClockType yourClock;
    myClock.setTime(14, 8, 25);
    yourClock.setTime(14, 25, 54);
    myClock.equalTime(yourClock);
    myClock.incrementHours();
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

bool ClockType::equalTime(const ClockType &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}

void ClockType::getTime(int &hour, int &minute, int &second) const
{
    hour = hr;
    minute = min;
    second = sec;
}

void ClockType::incrementHours()
{
    hr = ++hr % 24;
}

Car::Car(std::string ma, std::string mo, int y, long mi, std::string co, double gv)
{
    make = ma;
    model = mo;
    year = y;
    mileage = mi;
    color = co;
    GVWR = gv;
    started = false;
}

Car::Car()
{
}
