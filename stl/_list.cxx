#include "_list.hxx"

void stl_list_usageI()
{
    std::list<Bar> list;
    Bar x;

    // 调用转移构造函数
    list.insert(list.begin(), Bar());
    // 调用拷贝构造函数
    list.insert(list.begin(), x);
    list.insert(list.end(), x);
    list.emplace_back();
    // 调用拷贝构造函数
    list.emplace(list.end(), x);
}
