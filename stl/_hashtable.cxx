#include <unordered_map>

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

    // Bar()为右值，在插入时会调用转移构造函数
    hashtable.insert({14, Bar()});

    // 首先创建pair，此时y作为参数进栈并调用Bar的拷贝构造函数，
    // 然后pair实例会被std::move转换为右值，随后调用Bar的转移构造函数
    Bar y;
    hashtable.insert({15, y});
}
