#include "_vector.hxx"

void stl_vector_usageI()
{
    std::vector<Bar> vecI;
    
    // nsert函数中Bar()为右值, 通过移动语义将Bar的资源转移到vector的元素中
    vecI.insert(vecI.begin(), Bar());

    // insert函数中Bar()为左值, vector将x通过拷贝构造函数将存入元素中
    // 此处insert无论从begin还是end都调用了转移构造函数，一方面是推测为触发了扩容，
    // 另一方面从头部插入数据需要把当前位置的元素往后移动一位
    Bar x;
    vecI.insert(vecI.begin(), x);

    // 第三次调用insert调用了两次转移构造函数，推测触发了扩容
    vecI.insert(vecI.end(), x);
    // 第四次仅调用拷贝构造函数未触发扩容
    vecI.insert(vecI.end(), x);
    // 第五次调用了四次转移构造函数，推测触发扩容
    vecI.insert(vecI.end(), x);
    // 连续两次调用拷贝构造函数未调用转移构造函数，推测未触发扩容
    vecI.insert(vecI.end(), x);
    vecI.insert(vecI.end(), x);
    // 从头部插入数据
    vecI.insert(vecI.begin(), x);

    // 调用了默认构造函数，同时触发了扩容
    vecI.emplace(vecI.end());
    // operator[]获取vector元素
    std::cout << vecI[0].data() << std::endl;
}
