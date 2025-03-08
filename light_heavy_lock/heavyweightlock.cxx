#include "heavyweightlock.h"

HeavyweightLock::HeavyweightLock() :
    lock_acquired(false)
{

}

HeavyweightLock::~HeavyweightLock()
{

}

void HeavyweightLock::lock()
{
    std::unique_lock<std::mutex> lock(mtx);
    lock_acquired.store(true, std::memory_order_release);
}

void HeavyweightLock::unlock()
{
    if (lock_acquired.load(std::memory_order_acquire)) {
        mtx.unlock();
        lock_acquired.store(false, std::memory_order_release);
    }
}
