#include <iostream>
#include <memory>
#include <cmath>

#include "inlineclass.hxx"

template <typename... Args>
auto sum(Args... args) {
    return (... + args);  // 使用折叠表达式
}


int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;
    /*
     * Inline Variables
     * allow class to define a static member as inline so you do not need to define it again externally.
     */
    InlineClass::count = 100;

    /*
     * Structured Bindings
     */
    std::tuple<int, double, std::string> my_tuple = {42, 3.14, "Hello"};
    auto [a, b, c] = my_tuple;

    std::pair<int, double> my_pair = {10, 2.718};
    auto [x, y] = my_pair;
    std::cout << x << ", " << y << std::endl;

    /*
     * Folder Expressions
     */
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
    // std::cout << sum(1, 2, 3, 4, my_tuple) << std::endl; wrong
    return 0;
}
