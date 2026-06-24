#include <iostream>
#include <limits>
#include "movieTimes.h"

// Module 3B(a): In-Class Activity
// compile input for 5 movies including their times submit a file with your input

MovieTimes enterMovie();
void resetStream();
int inputHours();
int inputMinutesOrSeconds(std::string part);

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
    std::cout << newMovie.tostring() << std::endl;
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
    return theMovie;
}

Clock *makeClock()
{
    int hour = inputHours();
    int minute = inputMinutesOrSeconds("minutes");
    int second = inputMinutesOrSeconds("seconds");
    Clock *newClock = new Clock(hour, minute, second);
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
