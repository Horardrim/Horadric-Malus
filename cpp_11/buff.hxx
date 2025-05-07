#ifndef BUFF_HXX
#define BUFF_HXX

#include <iostream>
#include <cstring>
#include <algorithm>

#if __cplusplus >= 201103L
#define SUPPORTS_CPP11
#endif

class Buffer {
    private:
        size_t size;
        char* data;
    
        // 交换函数
        void swap(Buffer& other);
    public:
        // 构造函数
        Buffer(size_t size);
    
        // 拷贝构造函数
        Buffer(const Buffer& other);
    
        // 拷贝赋值运算符
        Buffer& operator=(const Buffer& other);
    
        // 析构函数
        ~Buffer();

        // 获取数据大小
        inline size_t getSize() const;
    
        // 获取数据指针
        inline char* getData() const;
    
    #ifdef SUPPORTS_CPP11
        // 移动构造函数
        Buffer(Buffer&& other) noexcept;
    
        // 移动赋值运算符
        Buffer& operator=(Buffer&& other) noexcept;
    #endif
        // 模拟移动构造函数
        Buffer(Buffer& other);
    
        // 模拟移动赋值运算符
        Buffer& operator=(Buffer& other); 
};

#endif
