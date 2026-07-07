#include "drink.h"

drink::drink(baseType b, tempType t, sizeType s, std::string dairy)
{
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(dairy);
}

void drink::setBase(baseType b)
{
    base = b;
}

void drink::setTemperature(tempType t)
{
    temp = t;
}

void drink::setSize(sizeType s)
{
    size = s;
}

void drink::setDairy(std::string d)
{
    dairy = d;
}

void drink::addFlavor(flavType f)
{
    flavors.insert(f);
}
void drink::removeFlavor(flavType f)
{
    flavors.erase(f);
}
void drink::removeAllFlavor()
{
    flavors.clear();
}
std::string drink::getBaseStr() const
{
    return baseToStr[base];
}

std::string drink::getTemperature() const
{
    return tempToStr[temp];
}

std::string drink::getSize() const
{
    return sizeToStr[size];
}

std::string drink::getDairy() const
{
    return dairy;
}

std::string drink::getFlavor() const
{
    std::ostringstream out;
    if (flavors.empty())
    {
        return "None";
    }
    std::set<flavType>::iterator it = flavors.begin();
    out << flavToStr[*it];
    for (++it; it != flavors.end(); ++it)
    {
        out << ", " << flavToStr[*it];
    }
    return out.str();
}

double drink::getPrice() const
{
    double price = 0;
    switch (size)
    {
    case sizeType::SMALL:
        price = 2;
        break;
    case sizeType::MED:
        price = 3;
        break;
    case sizeType::LARGE:
        price = 4;
        break;
    }
    switch (base)
    {
    case COFFEE:
        price += 2.75;
        break;
    case TEA:
        price += 1.75;
        break;
    case CREAM:
        break;
    }
    switch (temp)
    {
    case HOT:
        break;
    case ICE:
        price += .5;
        break;
    case BLEND:
        price += .75;
        break;
    }
    price += .25 * flavors.size();
    std::string lowerD = dairy;
    std::transform(lowerD.begin(), lowerD.end(), lowerD.begin(), ::tolower);
    if (lowerD == "whole milk")
    {
        price += .75;
    }
    else if (lowerD == "skim milk")
    {
        price += .75;
    }
    else if (lowerD == "cream")
    {
        price += 1.5;
    }
    else if (lowerD == "oat milk")
    {
        price += 2;
    }
    else if (lowerD == "almond milk")
    {
        price += 2;
    }
    else
    {
        price += .5;
    }

    return price;
}

std::string drink::toString() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << "Size: " << getSize() << std::endl;
    out << "Base: " << getBaseStr() << std::endl;
    out << "Temperature: " << getTemperature() << std::endl;
    out << "Flavor: " << getFlavor() << std::endl;
    out << "Dairy: " << getDairy() << std::endl;
    out << "Price: $" << getPrice() << std::endl;

    return out.str();
}

bool drink::operator>=(const drink &rightDrink) const
{
    double lprice = this->getPrice();
    double rprice = rightDrink.getPrice();
    return lprice >= rprice;
}

std::ostream &operator<<(std::ostream &out, const drink &d)
{
    out << d.toString();
    return out;
}

std::map<baseType, std::string> drink::baseToStr = {{COFFEE, "Coffee"}, {TEA, "Tea"}, {CREAM, "Cream"}};
std::map<drink::tempType, std::string> drink::tempToStr = {{drink::HOT, "Hot"},
                                                           {drink::ICE, "Iced"},
                                                           {drink::BLEND, "Blended"}};
std::map<sizeType, std::string> drink::sizeToStr = {{sizeType::SMALL, "Small"},
                                                    {sizeType::MED, "Medium"},
                                                    {sizeType::LARGE, "Large"}};
std::map<std::string, baseType> drink::strToBase = {{"COFFEE", COFFEE},
                                                    {"TEA", TEA},
                                                    {"CREAM", CREAM}};
std::map<std::string, drink::tempType> drink::strToTemp = {{"hot", drink::HOT},
                                                           {"iced", drink::ICE},
                                                           {"blended", drink::BLEND}};
std::map<std::string, sizeType> drink::strToSize = {{"SMALL", sizeType::SMALL},
                                                    {"MEDIUM", sizeType::MED},
                                                    {"LARGE", sizeType::LARGE}};
std::map<flavType, std::string> drink::flavToStr = {{HAZELNUT, "Hazelnut"},
                                                    {APPLE, "Apple"},
                                                    {BUTTERPECAN, "Butter Pecan"},
                                                    {BLUEBERRY, "Blueberry"},
                                                    {CARAMEL, "Caramel"},
                                                    {PEACH, "Peach"},
                                                    {MOCHA, "Mocha"},
                                                    {RASPBERRY, "Raspberry"},
                                                    {FRENCHVANILLA, "French Vanilla"},
                                                    {STRAWBERRY, "Strawberry"},
                                                    {PEPPERMINT, "Peppermint"},
                                                    {MANGO, "Mango"}};
;
std::map<std::string, flavType> drink::strToFlav = {};