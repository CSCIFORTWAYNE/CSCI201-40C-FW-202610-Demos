#include <iostream>
#include <vector>
int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int low, int high = 0);
int main()
{
    std::vector<int> list;
    list.push_back(5);
    // list[3] = 7;

    try
    {
        int x = inputInt("enter a number ", "error", isGTX);
        std::cout << x << std::endl;
        list.at(3) = x;
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

    return 0;
}

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;

    if (!std::cin)
    {
        throw 8;
    }
    if (!valid(num, low, high))
    {
        throw 10;
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