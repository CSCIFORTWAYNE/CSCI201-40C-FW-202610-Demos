#ifndef DRINK_H
#define DRINK_H
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>

enum baseType
{
    COFFEE,
    TEA,
    CREAM
};
enum sizeType
{
    SMALL,
    MED,
    LARGE
};

enum flavType
{
    HAZELNUT,
    APPLE,
    BUTTERPECAN,
    BLUEBERRY,
    CARAMEL,
    PEACH,
    MOCHA,
    RASPBERRY,
    FRENCHVANILLA,
    STRAWBERRY,
    PEPPERMINT,
    MANGO

};
enum tempType
    {
        HOT,
        ICE,
        BLEND
    };
    
const int NUM_DAIRY = 6;
const int NUM_FLAV = 12;

const std::string dairyStr[] = {"None",
                                "Skim Milk",
                                "Whole Milk",
                                "Oat Milk",
                                "Cream",
                                "Almond Milk"};
class drink
{
public:
    
    drink(baseType b, tempType t, sizeType s, std::string dairy);
    std::string getBaseStr() const;
    std::string getTemperature() const;
    std::string getSize() const;
    std::string getDairy() const;
    std::string getFlavor() const;
    double getPrice() const;
    void setBase(baseType b);
    void setTemperature(tempType t);
    void setSize(sizeType s);
    void setDairy(std::string d);
    void addFlavor(flavType);
    void removeFlavor(flavType);
    void removeAllFlavor();
    std::string toString() const;
    static std::map<baseType, std::string> baseToStr; // map for output
    static std::map<std::string, baseType> strToBase; // map for input
    static std::map<sizeType, std::string> sizeToStr;
    static std::map<std::string, sizeType> strToSize;
    static std::map<tempType, std::string> tempToStr;
    static std::map<std::string, tempType> strToTemp;
    static std::map<flavType, std::string> flavToStr;
    static std::map<std::string, flavType> strToFlav;
    bool operator>=(const drink &rightDrink) const;
    friend std::ostream &operator<<(std::ostream &, const drink &);

private:
    baseType base;
    tempType temp;
    sizeType size;
    std::string dairy;
    std::set<flavType> flavors;
};

#endif