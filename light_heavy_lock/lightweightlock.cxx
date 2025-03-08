#include "lightweightlock.h"
#include <iostream>
#include <sstream>

LightweightLock::LightweightLock() :
    lock_acquired(false)
{

}

LightweightLock::~LightweightLock()
{

}

void LightweightLock::lock()
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    if (lock.try_lock()) {
        std::ostringstream oss;
        oss <<  "get lock ok\n";
        std::cout << oss.str();
        lock_acquired.store(true, std::memory_order_release);
    } else {
        std::ostringstream oss;
        oss <<  "get lock not ok\n";
        std::cout << oss.str();
        lock_acquired.store(false, std::memory_order_release);
    }
}

void LightweightLock::unlock()
{
    if (lock_acquired.load(std::memory_order_acquire)) {
        mtx.unlock();
        lock_acquired.store(false, std::memory_order_release);
    }
}

bool LightweightLock::is_locked() const
{
    return lock_acquired.load(std::memory_order_acquire);
}
