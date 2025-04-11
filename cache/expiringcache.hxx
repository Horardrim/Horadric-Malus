#include <unordered_map>
#include <thread>
#include <chrono>
#include <mutex>

class ExpiringCache {
public:
    ExpiringCache(int expirationTime) : expirationTime(expirationTime) {}

    void put(int key, int value) {
        std::lock_guard<std::mutex> lock(mutex);
        cache[key] = {value, std::chrono::system_clock::now() + std::chrono::seconds(expirationTime)};
    }

    int get(int key) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        if (std::chrono::system_clock::now() > it->second.second) {
            cache.erase(it);
            return -1;
        }
        return it->second.first;
    }

private:
    int expirationTime;
    std::unordered_map<int, std::pair<int, std::chrono::system_clock::time_point>> cache;
    std::mutex mutex;
};
