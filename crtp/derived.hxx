#ifndef DERIVED_HXX
#define DERIVED_HXX

#include "base.hxx"

class Derived : public Base<Derived>
{
public:
    void implementation();
};



#endif
