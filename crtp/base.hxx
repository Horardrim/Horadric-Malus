#ifndef BASE_HXX
#define BASE_HXX

template<typename T>
class Base
{
public:
    void interface()
    {
        static_cast<T*>(this)->implementation();
    }
};


#endif
