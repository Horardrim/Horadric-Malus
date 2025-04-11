#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>

class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        // Update frequency and move to the correct frequency list
        auto& entry = cache[key];
        freqList[entry.freq].erase(entry.it);
        entry.freq++;
        freqList[entry.freq].push_front(key);
        entry.it = freqList[entry.freq].begin();
        return entry.value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and frequency
            auto& entry = cache[key];
            freqList[entry.freq].erase(entry.it);
            entry.freq++;
            freqList[entry.freq].push_front(key);
            entry.it = freqList[entry.freq].begin();
            entry.value = value;
        } else if (cache.size() == capacity) {
            // Remove the least frequently used item
            for (auto& list : freqList) {
                if (!list.second.empty()) {
                    int key = list.second.back();
                    list.second.pop_back();
                    cache.erase(key);
                    break;
                }
            }
        }
        freqList[1].push_front(key);
        cache[key] = {value, 1, freqList[1].begin()};
    }

private:
    int capacity;
    struct CacheEntry {
        int value;
        int freq;
        std::list<int>::iterator it;
    };
    std::unordered_map<int, CacheEntry> cache;
    std::vector<std::list<int>> freqList(10000); // Frequency list
};
