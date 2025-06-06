#include <iostream>
#include <memory>
#include <cmath>

template<typename T>
concept always_satisfied = true;

template <typename T>
concept integral = std::is_integral_v<T>;

/*  requires关键字在模板中的使用  */
template <typename T>
requires std::is_integral_v<T>
T add(T a, T b) {
    return a + b;
}

/*  直接使用concept  */
template <integral  T>
T add_( T a, T b)
{
    return a + b;
}

class Bar
{
public:
    Bar() = default;
    int value()
    {  return 10; }
};

class Bar_
{
public:
    Bar_() = default;
};

/* 
 * 一个自定义requires的子句 
 * T中必须有一个int value()成员函数
 */
template <typename T>
requires requires(T t) { { t.value() } -> std::same_as<int>; }
void print_value(T t) {
    std::cout << "Value: " << t.value() << std::endl;
}

int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;
    /*
     * concept 
     */
    add_(1, 2);

    print_value(Bar()); // can pass compiling and output 10
    // print_value(Bar_()); // can not pass compiling
    return 0;
}
