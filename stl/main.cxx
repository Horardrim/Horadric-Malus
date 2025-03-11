#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>

template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

// template <class T>
// struct iterator_traits<T*> {
//     typedef random_access_iterator_tag iterator_category;
//     typedef T value_type;
//     typedef ptrdiff_t difference_type;
//     typedef T* pointer;
//     typedef T& reference;
// };

// 泛化版本
template <typename Iterator>
size_t __distance(Iterator first, Iterator last, std::input_iterator_tag) {
    size_t count = 0;
    while (first != last) {
        ++count;
        ++first;
    }
    return count;
}

// 针对随机访问迭代器的特化版本
template <typename Iterator>
size_t __distance(Iterator first, Iterator last, std::random_access_iterator_tag) {
    return last - first;
}

// 用户接口
template <typename Iterator>
size_t distance(Iterator first, Iterator last) {
    using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
    return __distance(first, last, iterator_category());
}

int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;

    std::cout << "page size: " << getpagesize() << std::endl;


    return 0;
}
