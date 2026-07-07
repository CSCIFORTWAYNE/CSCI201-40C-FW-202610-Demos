#include <iostream>
#include <random>
#include <vector>
#include "drink.h"
#include "twelveHrClock.h"
#include "twentyFourHrClock.h"

int max(int, int);
double max(double, double);
char max(char, char);

template <class t>
t maxTemplate(t, t);

// M05 - part A lab
// fill in the strToFlav map. Strings should be in all upper case or all lower case.
//  add two new flavor enums. Add the pieces to both maps.

int main()
{
    int x = 8;
    int y = 4;
    std::cout << max(x, y) << std::endl;
    std::cout << maxTemplate(x, y) << std::endl;

    drink d1(COFFEE, drink::HOT, sizeType::LARGE, "Milk");
    d1.addFlavor(MOCHA);
    d1.addFlavor(CARAMEL);
    drink d2(COFFEE, drink::ICE, sizeType::LARGE, "Milk");
    d2.addFlavor(MOCHA);
    d2.addFlavor(CARAMEL);
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << maxTemplate(d1, d2).toString() << std::endl;

    std::default_random_engine generator(time(0)); // seed is added as part of the constructor
    std::uniform_int_distribution<int> twelveHrDist(1, 12);
    std::uniform_int_distribution<int> twentyFourHrDist(0, 23);
    std::uniform_int_distribution<int> minSecDist(0, 59);
    std::uniform_int_distribution<int> partDistribution(0, 1);
    TwelveHrClock randomClock(twelveHrDist(generator), minSecDist(generator), minSecDist(generator), partDistribution(generator) ? TwelveHrClock::AM : TwelveHrClock::PM);

    std::cout << randomClock << std::endl;
    std::vector<Clock *> vector1;
    int i = 0;
    while (true)
    {
        std::string more = "yes";
        std::cout << "Do you want more clocks? ";
        std::getline(std::cin >> std::ws, more);
        if (more != "yes")
        {
            break;
        }
        if (partDistribution(generator))
        {
            TwentyFourHrClock *newRandomClock = new TwentyFourHrClock(twentyFourHrDist(generator), minSecDist(generator), minSecDist(generator));
            vector1.push_back(newRandomClock);
        }
        else
        {
            TwelveHrClock::PartOfDayType part;
            std::string partStr;
            std::cout << "Is the clock AM or PM? ";
            std::cin >> partStr;
            while (!TwelveHrClock::strToPartMap.count(partStr))
            {
                std::cout << "Please Enter AM or PM. ";
                std::cin >> partStr;
            }
            part = TwelveHrClock::strToPartMap[partStr];
            vector1.push_back(new TwelveHrClock(twelveHrDist(generator), minSecDist(generator), minSecDist(generator), part));
        }
        std::cout << *vector1[i] << std::endl;
        i++;
    }
    std::cout << "final clock list" << std::endl;
    for (int i = 0; i < vector1.size(); i++)
    {
        std::cout << *vector1[i] << std::endl;
        delete vector1[i];
    }

    return 0;
}

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

char max(char a, char b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

double max(double a, double b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <class t>
t maxTemplate(t a, t b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
