#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <memory>
#include "movieTimes.h"

// Module 3B(a): In-Class Activity
// compile input for 5 movies including their times submit a file with your input

MovieTimes enterMovie();
void resetStream();
int inputHours();
int inputMinutesOrSeconds(std::string part);
TwelveHrClock::partOfDayType inputPartOfDay();
std::shared_ptr<TwelveHrClock> makeClock();
void movie(MovieTimes m);
int main()
{
    int x = 45;
    int y = 22;
    x = y;
    y = 28;
    int *xptr;
    int *yptr;
    xptr = new int(34);
    yptr = new int(22);
    *xptr = *yptr;
    *yptr = 29;
    delete xptr;
    xptr = nullptr;
    delete yptr;
    MovieTimes newMovie = enterMovie();
    MovieTimes newMovie2 = enterMovie();
    movie(newMovie);
    std::cout << newMovie.tostring() << std::endl;
    std::cout << newMovie2.tostring() << std::endl;
    return 0;
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
        std::shared_ptr<TwelveHrClock> clock = makeClock();
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

std::shared_ptr<TwelveHrClock> makeClock()
{
    int hour = inputHours();
    int minute = inputMinutesOrSeconds("minutes");
    TwelveHrClock::partOfDayType part = inputPartOfDay();

    std::shared_ptr<TwelveHrClock> newClock = std::make_shared<TwelveHrClock>(hour, minute, part);
    return newClock;
}
void movie(MovieTimes m)
{
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
    while (!std::cin || time < 0 || time > 59)
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
