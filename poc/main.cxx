#include <iostream>

#include "parent_child_class.hxx"

int main() {

    ChildClass* p = new ChildClass();
    ParentClass * p2 = static_cast<ParentClass*>(p);

    /* 输出：
     * child p: 0xa00000454
     * parent p: 0xa00000454
     * p->d的指针与p2->a的指针差值为12，正好是ParentClass中3个int成员的大小
    */
    std::cout << "child p: " << p->getAddress() << std::endl;
    std::cout << "parent p: " << p2->getAddress() << std::endl;
    return 0;
}
