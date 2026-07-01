#include "twentyfourHrClock.h"
#include <iostream>

int main()
{
    TwentyFourHrClock c(12, 22, 33);
    TwentyFourHrClock d(12, 33, 22);
    incrementClock(c);
    int x = 7;
    int y = 8;
    x = x + 3;
    c + 10;
    10 + c;
    if (d > c || c < d) // x.operator>(y);
    {
    }
    // std::cout << c;
    return 0;
}