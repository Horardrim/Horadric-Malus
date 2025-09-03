#include <iostream>

#include "parent_child_class.hxx"
#include "mem_pool.hxx"

int main() {

    ChildClass* p = new ChildClass();
    ParentClass * p2 = static_cast<ParentClass*>(p);

    /* 输出：
     * child p: 0x64d1d2b4b2c4
     * parent p: 0x64d1d2b4b2b8
     * p->d的指针与p2->a的指针差值为12，正好是ParentClass中3个int成员的大小
     */
    std::cout << "child p: " << p->getAddress() << std::endl;
    std::cout << "parent p: " << p2->getAddress() << std::endl;

    /*
     * usage of a thread-safe memory pool.
     */
    blocks[0].next.store(0, std::memory_order_relaxed);
    head.store(1, std::memory_order_release);

    void * pp = allocate();
    if (p) {
        printf("拿到一块内存：%p\n", p);
        // 使用这块内存
        std::snprintf(static_cast<char*>(pp), BLOCK_SIZE, "hello");
        printf("内容：%s\n", static_cast<char*>(pp));
    } else {
        printf("没有空闲块\n");
    }

    void * pp2 = allocate();
    (void) pp2;

    return 0;
}
