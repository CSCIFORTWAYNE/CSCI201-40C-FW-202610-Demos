#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>
#include "twentyFourHrClock.h"
#include "twelveHrClock.h"
#include "inputExcept.h"

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
int inputInt(std::string prompt);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int low, int high = 0);
Clock *makeClock();
int inputClockType();
TwelveHrClock::PartOfDayType inputPartOfDay();
void resetStream();

int main()
{
    std::vector<int> list;
    list.push_back(5);
    // list[3] = 7;
    TwentyFourHrClock clock;
    // std::cout << clock << std::endl;
    // clock = clock + 10;
    // std::cout << clock << std::endl;
    // clock = 10 + clock;
    std::cout << clock << std::endl;
    TwelveHrClock clock12;
    // clock12++;
    if (clock12 == clock)
    {
        std::cout << "The clocks have the same time" << std::endl;
    }
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution distribution(1, 100);
    try
    {
        int x = inputInt("enter a number ", "error", isGTX);
        std::cout << x << std::endl;
        // list.at(3) = x;
        // TwentyFourHrClock newclock(distribution(generator), distribution(generator), distribution(generator));
        // std::cout << newclock << std::endl;
        Clock *newClock = makeClock();
        std::cout << *newClock << std::endl;
        delete newClock;
    }

    catch (int n)
    {
        if (n == 8)
        {
            std::cout << "input failure detected" << std::endl;
        }
        else if (n == 10)
        {
            std::cout << "negative input detected" << std::endl;
        }
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;

    while (!std::cin || !valid(num, low, high)) //* !std::cin checks for input failure
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << error << std::endl;
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
    }
    return num;
}

bool isIntInRange(int num, int low, int high)
{
    return num >= low && num <= high;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

bool isGTX(int num, int low, int high)
{
    return num > low;
}

Clock *makeClock()
{
    Clock *clockptr = nullptr;
    int type = inputClockType();
    std::string hourPrompt = "Enter the clock's hour: ";
    std::string minPrompt = "Enter the clock's minutes: ";
    std::string secPrompt = "Enter the clock's seconds: ";
    int hour;
    int min;
    int sec;
    bool validHour = false;
    bool validMin = false;
    bool validSec = false;
    bool validAM = false;
    bool retry = true;
    while (retry)
    {
        if (!validHour)
        {
            try
            {
                hour = inputInt(hourPrompt);
            }
            catch (const Input_Exception &e)
            {
                std::cout << "Please enter a number for the hour." << std::endl;
                if (e.hasStreamReset())
                {
                    validHour = false;
                    continue;
                }
            }

            validHour = true;
        }
        if (!validMin)
        {
            try
            {
                min = inputInt(minPrompt);
            }
            catch (const Input_Exception &e)
            {
                if (e.hasStreamReset())
                {
                    validMin = false;
                    continue;
                }
            }
            validMin = true;
        }
        if (!validSec)
        {
            try
            {
                sec = inputInt(secPrompt);
            }
            catch (const Input_Exception &e)
            {
                if (e.hasStreamReset())
                {
                    validSec = false;
                    continue;
                }
            }
            validSec = true;
        }
        TwelveHrClock::PartOfDayType part;
        try
        {
            if (type == 12)
            {
                if (!validAM)
                {
                    part = inputPartOfDay();
                    validAM = true;
                }
                clockptr = new TwelveHrClock(hour, min, sec, part);
            }
            else
            {
                clockptr = new TwentyFourHrClock(hour, min, sec);
            }
            retry = false;
        }
        catch (Invalid_Hour e)
        {
            std::cout << e.what() << std::endl;
            if (e.getHour() != -1)
            {
                int low;
                int high;
                e.getHourRange(low, high);
                std::cout << "Valid hours are between " << low << " and " << high << "." << std::endl;
            }
            validHour = false;
        }
        catch (Invalid_Minute e)
        {
            std::cout << e.what() << std::endl;
            validMin = false;
            std::string yes;
            if (e.getMinute() < 0)
            {
                std::cout << "The entered minute is less than 0. Would you like to try absolute value to fix it? ";
                std::cin >> yes;
                std::cout << std::endl;
                std::transform(yes.begin(), yes.end(), yes.begin(), ::tolower);
                if (yes == "yes")
                {
                    min = abs(min);
                    validMin = true;
                }
            }
            else if (e.getMinute() > 59)
            {
                // repeat the fix with modulus
            }
            else
            {
                // would you like to enter the data again
                if (yes == "yes")
                {
                    validMin = false;
                }
                else
                {
                    throw std::runtime_error("Unable to proceed with error handling.");
                }
            }
        }
        catch (Invalid_Second e)
        {
            std::cout << e.what() << std::endl;
            validSec = false;
        }
    }
    return clockptr;
}

int inputInt(std::string prompt)
{
    int num;
    // bool validInput = false;

    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    try
    {
        if (!std::cin)
        {
            throw Input_Exception();
        }
    }
    catch (Input_Exception &e)
    {
        std::cout << e.what() << std::endl;
        resetStream();
        e.setStreamReset(true);
        throw;
    }

    return num;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

TwelveHrClock::PartOfDayType inputPartOfDay()
{
    int partInt = -1;
    std::string prompt = "Is it \n1. AM\n2. PM\n";
    partInt = inputInt(prompt, "Please enter 1 or 2.", isAorB, 1, 2);
    return TwelveHrClock::parts[partInt - 1];
}

int inputClockType()
{

    int timeInt = inputInt("Is the clock 12 hour or 24 hour? ", "Please enter 12 or 24.", isAorB, 12, 24);

    return timeInt;
}
