#include <unordered_map>
#include <iostream>

#include "_hashtable.hxx"
#include "bar.hxx"
#include <utility>

void stl_unordered_map_usageI()
{
    std::unordered_map<int, Bar> hashtable;
    // unordered_map[k]不存在，则会调用默认Bar()并将其赋给hashtable[k]
    // 然后调用Bar的赋值函数将x赋给unordered_map[k]
    Bar x;
    hashtable[10] = x;

    // insert函数中为了确保std::pair为一个右值会调用std::move, 因此会调用Bar的转移构造函数
    hashtable.insert({14, Bar()});

    // y为左值，构造pair时调用一次拷贝构造函数，insert时调用一次转移构造函数
    Bar y;
    hashtable.insert({15, y});

    std::cout << "===================" << std::endl;
    // emplace函数接受可变参数，并使用 std::forward 进行完美转发
    hashtable.emplace(12, Bar());
    hashtable.emplace(13, y);
}
