#ifndef HEAVY_WEIGHT_LOCK_H
#define HEAVY_WEIGHT_LOCK_H

#include <atomic>
#include <mutex>

class HeavyweightLock
{
public:
    HeavyweightLock();

    ~HeavyweightLock();

    void lock();

    void unlock();

private:
    std::mutex mtx;
    std::atomic<bool> lock_acquired;
};

#endif
