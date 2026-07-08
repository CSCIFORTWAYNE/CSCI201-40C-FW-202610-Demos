#include "inputExcept.h"

Input_Exception::Input_Exception() : std::runtime_error("Input Failure detected. Resetting stream.")
{
    streamReset = false;
}

void Input_Exception::setStreamReset(bool streamReset)
{
    this->streamReset = streamReset;
}

bool Input_Exception::hasStreamReset() const
{
    return streamReset;
}
