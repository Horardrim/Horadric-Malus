#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(size_t capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        // Move the accessed key to the front of the list
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update the value and move the key to the front
            lru.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            // Remove the least recently used item
            int last = lru.back();
            lru.pop_back();
            cache.erase(last);
        }
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }

private:
    const size_t capacity;
    // 缓存的键值对K为键值，V为缓存的值和迭代器组成的pair
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    // 最近最少使用的键的列表，保存的是键值
    std::list<int> lru;
};
