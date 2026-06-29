#include <iostream>
#include "person.h"
#include "employee.h"
#include "movieTimes.h"
#include <algorithm>

void printPerson(Person *p);
MovieTimes *enterMovie();
void resetStream();
int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
int inputHours();
int inputMinutesOrSeconds(std::string part);
TwelveHrClock::partOfDayType inputPartOfDay();
Clock *makeClock();
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int low, int high = 0);

int main()
{
    Employee emp("Harry Potter", 13, "555-1212", "hpotter@email.com", 23000.21, "2021-12-12");
    Person per("Charlie Brown", 11, "555-1234", "cbrown@email.com");
    printPerson(&emp);
    ShowTimes *shows[2];
    shows[0] = enterMovie();
    shows[1] = new ShowTimes("Clue the musical");
    TwelveHrClock t(4, 0, TwelveHrClock::partOfDayType::PM);
    Clock t1(11, 45);
    shows[1]->addTime(t);
    shows[1]->addTime(t1);

    std::cout << shows[0]->tostring() << std::endl;
    std::cout << shows[1]->tostring() << std::endl;
    delete shows[0];
    delete shows[1];
    return 0;
}

void printPerson(Person *p)
{
    std::cout << p->toString() << std::endl;
}

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || !valid(num, low, high))
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

MovieTimes *enterMovie()
{
    std::string title;
    std::string rating;
    int runtime;
    std::cout << "Enter the movie title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << std::endl;
    runtime = inputInt("Enter the runtime in minutes: ", "That is not a valid runtime. Please enter a number greater than 0.", isGTX);

    std::cout << "Enter the rating: ";
    std::cin >> std::ws;
    std::getline(std::cin, rating);
    std::cout << std::endl;
    MovieTimes *theMovie = new MovieTimes(title, runtime, rating);
    char more = 'y';
    while (more == 'y')
    {
        Clock *clock = makeClock();
        theMovie->addTime(*clock);
        delete clock;
        std::cout << "Would you like to add another showtime? ";
        std::cin >> more;
        std::cout << std::endl;
        more = tolower(more);
    }

    return theMovie;
}

TwelveHrClock::partOfDayType inputPartOfDay()
{
    std::string ampm;
    std::cout << "Is it AM or PM? ";
    std::cin >> ampm;
    std::transform(ampm.begin(), ampm.end(), ampm.begin(), ::toupper);
    while (ampm != "AM" && ampm != "PM")
    {
        std::cout << "Please enter AM or PM. ";

        std::cin >> ampm;
        std::transform(ampm.begin(), ampm.end(), ampm.begin(), ::toupper);
    }
    if (ampm == "AM")
    {
        return TwelveHrClock::partOfDayType::AM;
    }
    else
    {

        return TwelveHrClock::partOfDayType::PM;
    }
}

Clock *makeClock()
{
    int hour;
    int minute;
    int clockType;
    Clock *newClock = nullptr;
    std::string hourPrompt = "Enter the hour: ";
    clockType = inputInt("Is the time in 12 or 24 hours? ", "Please enter 12 or 24", isAorB, 12, 24);
    if (clockType == 12)
    {
        hour = inputInt(hourPrompt, "That is not a valid hour. Please enter an hour between 1 and 12.", isIntInRange, 1, 12);
    }
    else
    {
        hour = inputInt(hourPrompt, "That is not a valid hour. Please enter an hour between 0 and 23.", isIntInRange, 0, 23);
    }
    minute = inputInt("Enter the minutes: ", "That is not valid minutes. Please enter a number between 0 and 59", isIntInRange, 0, 59);
    if (clockType == 12)
    {
        TwelveHrClock::partOfDayType part = inputPartOfDay();
        newClock = new TwelveHrClock(hour, minute, part);
    }
    else
    {
        newClock = new Clock(hour, minute);
    }

    return newClock;
}
int inputHours()
{
    int hour;
    std::cout << "Enter the hour on the clock: ";
    std::cin >> hour;
    std::cout << std::endl;
    while (!std::cin || hour < 0 || hour > 23)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid hour. Please enter a number between 0 and 23." << std::endl;
        std::cout << "Enter the hour on the clock: ";
        std::cin >> hour;
        std::cout << std::endl;
    }
    return hour;
}
int inputMinutesOrSeconds(std::string part)
{
    int time;
    std::cout << "Enter the number of " << part << " on the clock: ";
    std::cin >> time;
    std::cout << std::endl;
    while (!std::cin || !isIntInRange(time, 0, 59))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid value for the number of " << part << ". Please enter a number between 0 and 59." << std::endl;
        std::cout << "Enter the number of " << part << " on the clock: ";
        std::cin >> time;
        std::cout << std::endl;
    }
    return time;
}

void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
