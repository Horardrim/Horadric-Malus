#ifndef SFINAE_HXX
#define SFINAE_HXX

#include <iostream>

// 前置声明
template <typename T>
class has_value;

// 辅助类型
struct yes { char data[1]; };
struct no { char data[2]; };

// 检查是否存在名为value的int型成员
template <typename T>
class has_value {
private:
    // 尝试访问T类的value成员
    template <typename C> static yes test(int C::*);
    template <typename C> static no test(...);

public:
    // 如果test<T>(0)匹配到yes类型，则value为true
    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

// 测试类
struct A {
    int value;
};

struct B {
    double value;
};

struct C {
    int val;
};

#endif
