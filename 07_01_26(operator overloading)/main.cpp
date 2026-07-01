#include "twentyfourHrClock.h"
#include <iostream>

int main()
{
    TwentyFourHrClock c(12, 22, 33);
    TwentyFourHrClock d(12, 33, 22);
    incrementClock(c);
    int x = 7;
    int y = 8;
    // x = x + 3;
    x++;
    int z = ++x;
    int a = x++;
    std::cout << z << std::endl;
    std::cout << a << std::endl;

    c + 10;
    10 + c;
    if (d > c || c < d) // x.operator>(y);
    {
    }
    std::cout << c << std::endl;
    std::cin >> d;
    while (!std::cin)
    {
        std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> d;
    }
    std::cout << d << std::endl;
    return 0;
}