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

    // insert函数中为了确保std::pair为一个右值会调用std::move, 因此会调用Bar的转移构造函数
    hashtable.insert({14, Bar()});

    // 同上
    Bar y;
    hashtable.insert({15, y});
}
