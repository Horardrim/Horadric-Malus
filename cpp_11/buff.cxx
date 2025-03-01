#include "buff.hxx"

Buffer::Buffer(size_t size) : 
    size(size),
    data(new char[size])
{
    std::memset(data, 0, size); // 初始化为0
}

Buffer::Buffer(const Buffer& other) :
    size(other.size),
    data(new char[other.size])
{
    std::memcpy(data, other.data, size);
}

Buffer& Buffer::operator=(const Buffer& other)
{
    if (this != &other) {
        Buffer temp(other);
        swap(temp);
    }
    return *this;
}

Buffer::~Buffer() {
    delete[] data;
}

void Buffer::swap(Buffer& other)
{
    std::swap(data, other.data);
    std::swap(size, other.size);
}

size_t Buffer::getSize() const
{
    return size;
}

char* Buffer::getData() const
{
    return data;
}

#ifdef SUPPORTS_CPP11

Buffer::Buffer(Buffer&& other) noexcept :
    size(0),
    data(nullptr)
{
    swap(other);
}

Buffer& Buffer::operator=(Buffer&& other) noexcept
{
    if (this != &other) {
        swap(other);
    }
    return *this;
}

#else

Buffer::Buffer(Buffer& other) :
    size(0),
    data(nullptr)
{
    swap(other);
}

Buffer& Buffer::operator=(Buffer& other)
{
    if (this != &other) {
        swap(other);
    }
    return *this;
}

 #endif
