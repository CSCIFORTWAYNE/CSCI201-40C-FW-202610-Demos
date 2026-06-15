#ifndef ROOM_H
#define ROOM_H
#include <string>
class Room
{
public:
    Room(std::string c, std::string b, int r);
    std::string getCampus() const;
    std::string getBuilding() const;
    int getRoomNum() const;
    std::string toString() const;

private:
    std::string campus;
    std::string building;
    int roomNum;
};

#endif