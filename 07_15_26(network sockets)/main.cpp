#include <cpr/cpr.h>
#include <iostream>

// cpr library found at https://github.com/libcpr/cpr
// in-class module 6 b use cpr to get a different webpage. how many lines of output were in the response.

int main()
{
    cpr::Response r = cpr::Get(cpr::Url{"https://netbsd.org"});
    std::cout << r.status_code << std::endl;
    std::cout << r.header["content-type"] << std::endl;
    std::cout << r.text << std::endl;
    return 0;
}