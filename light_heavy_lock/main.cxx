#include <unistd.h>

#include <iostream>
#include <sstream>
#include <memory>
#include <cmath>
#include <thread>
#include<vector>

#include "lightweightlock.h"
#include "heavyweightlock.h"

void worker(LightweightLock& light_lock, HeavyweightLock& heavy_lock, int id) {
    for (int i = 0; i < 10; ++i) {
        light_lock.lock();
        if (light_lock.is_locked()) {
            std::ostringstream oss;
            oss << "Thread " << id << " acquired lightweight lock.\n";
            std::cout << oss.str();
            std::this_thread::sleep_for(std::chrono::milliseconds(10000));
            light_lock.unlock();
        }
        else
        {
            heavy_lock.lock();
            std::ostringstream oss;
            oss << "Thread " << id << " failed to acquire lightweight lock, trying heavyweight lock.\n";
            std::cout << oss.str();

            std::ostringstream oss_;
            oss_ << "Thread " << id << " acquired heavyweight lock.\n";
            std::cout << oss_.str();
            std::this_thread::sleep_for(std::chrono::milliseconds(10000));
            heavy_lock.unlock();
        }
    }
}

int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;

    LightweightLock light_lock;
    HeavyweightLock heavy_lock;
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(worker, std::ref(light_lock), std::ref(heavy_lock), i);
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    return 0;
}
