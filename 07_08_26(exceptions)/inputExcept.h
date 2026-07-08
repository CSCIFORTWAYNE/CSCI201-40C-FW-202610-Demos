#ifndef INPUTE_H
#define INPUTE_H
#include <stdexcept>

class Input_Exception : public std::runtime_error
{
public:
    Input_Exception();
    void setStreamReset(bool);
    bool hasStreamReset() const;

private:
    bool streamReset;
};

#endif