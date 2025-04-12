#include "bar.hxx"

Bar::Bar() :
_data(new int(10))
{

}

Bar::Bar(const Bar& other) :
_data(new int(*other._data))
{

}

Bar::Bar(Bar && other) noexcept
{
    _data = other._data;
    other._data = nullptr;
}

Bar & Bar::operator=(const Bar & other)
{
    if(this != &other)
    {
        delete _data;
        _data = new int(*other._data);
    }
    return *this;
}

Bar & Bar::operator=(Bar && other) noexcept
{
    if (this != &other)
    {
        _data = other._data;
        other._data = nullptr;
    }
    return *this;
}

Bar::~Bar()
{
    if (_data == nullptr)
    {
        delete _data;
        _data = nullptr;
    }
}

