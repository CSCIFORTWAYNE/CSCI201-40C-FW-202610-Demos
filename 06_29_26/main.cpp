#include <iostream>
#include "person.h"
#include "employee.h"
#include "movieTimes.h"
#include <algorithm>

void printPerson(Person *p);
MovieTimes enterMovie();
void resetStream();
int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high);
int inputHours();
int inputMinutesOrSeconds(std::string part);
TwelveHrClock::partOfDayType inputPartOfDay();
Clock *makeClock();
bool isIntInRange(int num, int low, int high);

int main()
{
    Employee emp("Harry Potter", 13, "555-1212", "hpotter@email.com", 23000.21, "2021-12-12");
    Person per("Charlie Brown", 11, "555-1234", "cbrown@email.com");
    printPerson(&emp);
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
    while (!std::cin || valid(num, low, high))
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

MovieTimes enterMovie()
{
    std::string title;
    std::string rating;
    int runtime;
    std::cout << "Enter the movie title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << std::endl;

    std::cout << "Enter the runtime in minutes: ";
    std::cin >> runtime;
    std::cout << std::endl;
    while (!std::cin || runtime < 1)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid runtime. Please enter a number greater than 0." << std::endl;
        std::cout << "Enter the runtime in minutes: ";
        std::cin >> runtime;
        std::cout << std::endl;
    }
    std::cout << "Enter the rating: ";
    std::cin >> std::ws;
    std::getline(std::cin, rating);
    std::cout << std::endl;
    MovieTimes theMovie(title, runtime, rating);
    char more = 'y';
    while (more == 'y')
    {
        Clock *clock = makeClock();
        theMovie.addTime(*clock);

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
    int hour = inputInt("Enter the hour on the clock ", "That is not a valid hour. Please enter an hour between 1 and 12.", isIntInRange, 1, 12);
    int minute = inputMinutesOrSeconds("minutes");
    TwelveHrClock::partOfDayType part = inputPartOfDay();

    // Clock* newClock = (hour, minute, part);
    return nullptr;
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
