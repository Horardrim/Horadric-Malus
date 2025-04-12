#ifndef BAR_HXX
#define BAR_HXX

#include <string.h>
#include <stdlib.h>

class Bar
{
public:
    Bar();
    Bar(const int & data);
    Bar(const  Bar & other);
    Bar(Bar && other) noexcept;
    Bar & operator=(const Bar & other);
    Bar & operator=(Bar && other) noexcept;
    ~Bar();
private:
    int * _data;
};

#endif
