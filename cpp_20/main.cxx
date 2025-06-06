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

class Bar__
{
public:
    Bar__() = default;
    int value;
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


template <typename>
struct void_type {
    typedef void type;
};

template <typename T, typename = void>
struct has_value_function : std::false_type {};

template <typename T>
struct has_value_function<T, typename void_type<decltype(&T::value)>::type> : std::true_type {};

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

    /*
     * SFINAE机制
     */
    std::cout << "Bar has value member: " << has_value_function<Bar>::value << std::endl;
    std::cout << "Bar_ has not value member: " << has_value_function<Bar_>::value << std::endl;
    std::cout << "Bar__ has value function: " << has_value_function<Bar__>::value << std::endl;
    return 0;
}
