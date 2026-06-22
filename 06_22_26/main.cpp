#include <iostream>

void pointerManipulation(const int &x);

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

    return 0;
}

void pointerManipulation(int &x)
{
    int *y;
    y = &x;
    *y = 29;
    x = 37;
}
