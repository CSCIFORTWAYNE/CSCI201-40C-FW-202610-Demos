#include <iostream>
#include <limits>
#include "clock.h"

void pointerManipulation(const int &x);
void resetStream();
Clock *makeClock();
int inputHours();
int inputMinutesOrSeconds(std::string part);
void pointerParameters(int *&p, double *q);
int main()
{

    int *p = nullptr;
    int q = 7;
    // std::cout << *p << std::endl;

    p = &q;
    std::cout << *p << std::endl;
    std::cout << &q << std::endl;
    *p = 29;
    std::cout << q << std::endl;
    int numNums = 0;
    std::cout << "How many numbers? ";
    std::cin >> numNums;
    std::cout << std::endl;
    while (!std::cin || numNums < 1)
    {
        if (!std::cin) // if we have input failure
        {
            resetStream();
        }
        std::cout << "That is not valid. Please enter a number greater than 1." << std::endl;
        std::cout << "How many numbers? ";
        std::cin >> numNums;
        std::cout << std::endl;
    }

    int *x = new int[numNums];
    Clock *c1 = makeClock();
    Clock *c2 = makeClock();
    if (c1->equalTime(*c2))
    {
        std::cout << "They are the same time." << std::endl;
    }

    int *number = new int;
    *number = 25;
    double *secondNumber = new double;
    *secondNumber = 40.3;

    pointerParameters(number, secondNumber);

    int twoDArray[10][10]; // 10 rows and 10 columns
    int **dynamic2DArray;
    dynamic2DArray = new int *[10]; // create 10 rows
    dynamic2DArray[0] = new int[3]; // create 3 columns for the first row
    dynamic2DArray[1] = new int[7]; // create 7 columns in the second row
    dynamic2DArray[3] = new int;    // row 3 has a single dynamic variable
    Clock **clocks;
    clocks = new Clock *[numNums];
    for (int i = 0; i < numNums; i++)
    {
        clocks[i] = makeClock();
    }

    for (int i = 0; i < numNums; i++)
    {
        std::cout << clocks[i]->printTime() << std::endl;
        delete clocks[i];
    }
    delete[] clocks;
    delete[] x;
    delete c1;
    delete c2;
    delete number;
    delete secondNumber;
    delete[] dynamic2DArray[0];
    delete[] dynamic2DArray[1];
    delete dynamic2DArray[3];
    delete[] dynamic2DArray;

    return 0;
}

void pointerManipulation(int &x)
{
    int *y;
    y = &x;
    *y = 29;
    x = 37;
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
void pointerParameters(int *&p, double *q)
{
    delete p;
    p = new int();
    *p = 37;
    q = new double();
    *q = 12.5;
    delete q;
}
void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
