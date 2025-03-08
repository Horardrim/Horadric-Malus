#include <unistd.h>

#include <iostream>
#include <memory>
#include <cmath>

int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;

    std::cout << "page size: " << getpagesize() << std::endl;

    // align pointer
    unsigned long a = 10;
    unsigned long bytes_ = 4;
    (void) a;
    (void) bytes_;
    std::cout << "a 4 byte alignment: " << ((a + bytes_ - 1) & ~(bytes_ - 1)) << std::endl;
    std::cout << (1 & 1) << " " << (0 & 1) << std::endl;
    return 0;
}
