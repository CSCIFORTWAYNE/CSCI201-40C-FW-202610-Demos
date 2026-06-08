#include <iostream>
#include <string>

class car
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

int main()
{
    car c;
    c.make = "honda";
    std::cout << "hello world" << std::endl;
    return 0;
}