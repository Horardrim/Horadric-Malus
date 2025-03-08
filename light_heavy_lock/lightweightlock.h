#ifndef LIGHT_WEIGHT_LOCK_H
#define LIGHT_WEIGHT_LOCK_H

#include <atomic>
#include <mutex>

class LightweightLock
{
public:
    LightweightLock();

    ~LightweightLock();

    void lock();

    void unlock();

    bool is_locked() const;

private:
    std::mutex mtx;
    std::atomic<bool> lock_acquired;
};

#endif
