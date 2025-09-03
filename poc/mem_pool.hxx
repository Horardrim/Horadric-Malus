#ifndef MEM_POOL_HXX
#define MEM_POOL_HXX

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstdio>

constexpr std::size_t BLOCK_SIZE   = 64;
constexpr std::size_t BLOCK_COUNT  = 4;
constexpr std::size_t MASK         = BLOCK_COUNT - 1;

struct alignas(64) Block {
    std::atomic<std::size_t> next;     // 版本号 + 指针
    char data[BLOCK_SIZE];
};

Block blocks[BLOCK_COUNT];
std::atomic<std::size_t> head{0};      // 空闲链表头，初始 0 表示空

void* allocate() {
    std::size_t old_head = head.load(std::memory_order_acquire);
    for (;;) {
        if (old_head == 0)
        {
            return nullptr;          // 无空闲
        }
        // 计算环状数据结构的索引值，用于替代取模计算(MASK + 1必须是2的幂次才能正确计算取模)
        std::size_t new_head = (old_head & ~MASK) | ((old_head + 1) & MASK);

        // 如果head与old_head相同则将new_head写给head.
        if (head.compare_exchange_weak(old_head, new_head,
                                        std::memory_order_acq_rel)) {
            return &blocks[old_head & MASK].data;
        }
    }
}

#endif
