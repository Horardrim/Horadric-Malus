#include <iostream>
#include <memory>
#include <cmath>

#include "finalclass.hxx"

[[deprecated]]
void oldFunction() {
// call this will trigger compiler warning
}


template<typename T>
constexpr T * null_ptr = nullptr;

constexpr int square(int x)
{
    return x * x;
}

int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;
    /*
     * Generalized Attributes
     */
    // olfFunction();

    /*
     * constexpr
     * the variable/function which is decorated by constexpr shall be calculated at compiling time
     */
    // right
    constexpr int size = 10; (void) size;
    // right 
    const int a = 1, b = 2;
    constexpr int c = a + b; (void) c;
    // constexpr 函数可以在编译期和运行时都工作，这意味着你可以用同一个函数实现两种不同的用途，而不需要定义两个不同的函数。这不仅减少了代码冗余，还提高了代码的可维护性。
    int x = 10;
    std::cout << square(x) << std::endl;
    // wrong
    // int a = 1, b = 2;
    // constexpr int c = a + b; (void) c;

    /*
     * template variable
     * tips:
     * 1) template variable is not used to do dynamic allocate. Here I only assign a nullptr.
     */
    const FinalClass * t = null_ptr<FinalClass>;
    (void) t;

    /*
     * can use auto at a lambda
     */
    auto lambda = [](auto x, auto y) { return x + y; };
    std::cout << lambda(1, 2) << std::endl;  // 输出：3
    std::cout << lambda(1.5, 2.5) << std::endl;  // 输出：4

    /*
     * final class which can not be inherited
     */
    std::cout << std::is_final<FinalClass>::value << std::endl;


    auto up = std::make_unique<int>(20);
    std::cout << *up << std::endl;

    std::cout << std::hypot(12.0, 5.0) << std::endl;
    return 0;
}
