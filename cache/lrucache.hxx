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
    size_t capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> lru;
};
